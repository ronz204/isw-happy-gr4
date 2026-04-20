#pragma once

#include "SearchStrategy.h"
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>
#include <chrono>

class DijkstraStrategy : public SearchStrategy
{
private:
  struct NodeDistance
  {
    int nodeId;
    double distance;

    bool operator>(const NodeDistance &other) const
    {
      return distance > other.distance;
    }
  };

public:
  TraversalResult traverse(
      const Graph &graph,
      int startNodeId,
      const Profile &profile) const override
  {
    auto startTime = std::chrono::high_resolution_clock::now();

    TraversalResult result;
    result.algorithm = "Dijkstra";

    std::unordered_map<int, double> realDistances;  // Actual distances
    std::unordered_map<int, double> priorityDistances;  // Distances with bonuses for priority
    std::unordered_set<int> visited;
    std::priority_queue<NodeDistance, std::vector<NodeDistance>, std::greater<NodeDistance>> pq;

    // Initialize distances
    auto allNodeIds = graph.getAllNodeIds();
    for (int nodeId : allNodeIds)
    {
      realDistances[nodeId] = std::numeric_limits<double>::infinity();
      priorityDistances[nodeId] = std::numeric_limits<double>::infinity();
    }
    realDistances[startNodeId] = 0.0;
    priorityDistances[startNodeId] = 0.0;

    pq.push({startNodeId, 0.0});

    while (!pq.empty())
    {
      NodeDistance current = pq.top();
      pq.pop();

      if (visited.find(current.nodeId) != visited.end())
        continue;

      visited.insert(current.nodeId);
      result.visitedNodes.push_back(current.nodeId);
      result.cumulativeDistances.push_back(realDistances[current.nodeId]);  // Use real distance

      const auto *neighbors = graph.getNeighbors(current.nodeId);
      if (!neighbors)
        continue;

      for (const auto &neighbor : *neighbors)
      {
        if (visited.find(neighbor.toNodeId) != visited.end())
          continue;

        const Edge *edge = graph.getEdge(neighbor.edgeId);
        if (!edge || !profile.isEdgeAccessible(*edge))
          continue;

        double effectiveWeight = profile.calculateEffectiveWeight(*edge);
        double newRealDistance = realDistances[current.nodeId] + effectiveWeight;

        // Apply landmark bonus for priority calculation (NewStudent profile)
        double newPriorityDistance = newRealDistance;
        const Node *neighborNode = graph.getNode(neighbor.toNodeId);
        if (neighborNode)
        {
          newPriorityDistance += profile.getLandmarkBonus(*neighborNode);
        }

        if (newPriorityDistance < priorityDistances[neighbor.toNodeId])
        {
          realDistances[neighbor.toNodeId] = newRealDistance;
          priorityDistances[neighbor.toNodeId] = newPriorityDistance;
          pq.push({neighbor.toNodeId, newPriorityDistance});
        }
      }
    }

    result.nodesVisited = result.visitedNodes.size();

    auto endTime = std::chrono::high_resolution_clock::now();
    result.executionTimeMicros = std::chrono::duration_cast<std::chrono::microseconds>(
                                      endTime - startTime)
                                      .count();

    return result;
  }

  PathResult findPath(
      const Graph &graph,
      int startNodeId,
      int endNodeId,
      const Profile &profile) const override
  {
    auto startTime = std::chrono::high_resolution_clock::now();

    PathResult result;
    result.algorithm = "Dijkstra";
    result.pathExists = false;
    result.totalDistance = 0.0;

    std::unordered_map<int, double> realDistances;  // Actual distances
    std::unordered_map<int, double> priorityDistances;  // Distances with bonuses for priority
    std::unordered_map<int, int> parent;
    std::unordered_set<int> visited;
    std::priority_queue<NodeDistance, std::vector<NodeDistance>, std::greater<NodeDistance>> pq;

    // Initialize
    auto allNodeIds = graph.getAllNodeIds();
    for (int nodeId : allNodeIds)
    {
      realDistances[nodeId] = std::numeric_limits<double>::infinity();
      priorityDistances[nodeId] = std::numeric_limits<double>::infinity();
    }
    realDistances[startNodeId] = 0.0;
    priorityDistances[startNodeId] = 0.0;
    parent[startNodeId] = -1;

    pq.push({startNodeId, 0.0});

    while (!pq.empty())
    {
      NodeDistance current = pq.top();
      pq.pop();

      if (visited.find(current.nodeId) != visited.end())
        continue;

      visited.insert(current.nodeId);

      // Found the destination
      if (current.nodeId == endNodeId)
      {
        result.pathExists = true;
        break;
      }

      const auto *neighbors = graph.getNeighbors(current.nodeId);
      if (!neighbors)
        continue;

      for (const auto &neighbor : *neighbors)
      {
        if (visited.find(neighbor.toNodeId) != visited.end())
          continue;

        const Edge *edge = graph.getEdge(neighbor.edgeId);
        if (!edge || !profile.isEdgeAccessible(*edge))
          continue;

        double effectiveWeight = profile.calculateEffectiveWeight(*edge);
        double newRealDistance = realDistances[current.nodeId] + effectiveWeight;

        // Apply landmark bonus for priority calculation (NewStudent profile)
        // This makes landmark routes more attractive without distorting actual distances
        double newPriorityDistance = newRealDistance;
        const Node *neighborNode = graph.getNode(neighbor.toNodeId);
        if (neighborNode)
        {
          newPriorityDistance += profile.getLandmarkBonus(*neighborNode);
        }

        if (newPriorityDistance < priorityDistances[neighbor.toNodeId])
        {
          realDistances[neighbor.toNodeId] = newRealDistance;
          priorityDistances[neighbor.toNodeId] = newPriorityDistance;
          parent[neighbor.toNodeId] = current.nodeId;
          pq.push({neighbor.toNodeId, newPriorityDistance});
        }
      }
    }

    if (result.pathExists)
    {
      // Reconstruct path
      std::vector<int> reversePath;
      int current = endNodeId;

      while (current != -1)
      {
        reversePath.push_back(current);
        current = parent[current];
      }

      result.path = std::vector<int>(reversePath.rbegin(), reversePath.rend());

      // Calculate segment distances using REAL distances
      for (size_t i = 0; i < result.path.size() - 1; i++)
      {
        int from = result.path[i];
        int to = result.path[i + 1];
        double segmentDist = realDistances[to] - realDistances[from];
        result.segmentDistances.push_back(segmentDist);
      }

      result.totalDistance = realDistances[endNodeId];
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    result.executionTimeMicros = std::chrono::duration_cast<std::chrono::microseconds>(
                                      endTime - startTime)
                                      .count();

    return result;
  }

  std::string getName() const override { return "Dijkstra"; }
};
