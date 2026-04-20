#pragma once

#include "SearchStrategy.h"
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <chrono>

class BFSStrategy : public SearchStrategy
{
public:
  TraversalResult traverse(
      const Graph &graph,
      int startNodeId,
      const ProfileContext &context) const override
  {
    auto startTime = std::chrono::high_resolution_clock::now();

    TraversalResult result;
    result.algorithm = "BFS";

    std::unordered_set<int> visited;
    std::queue<std::pair<int, double>> queue; // {nodeId, cumulativeDistance}

    queue.push({startNodeId, 0.0});
    visited.insert(startNodeId);

    while (!queue.empty())
    {
      auto [currentNode, currentDistance] = queue.front();
      queue.pop();

      result.visitedNodes.push_back(currentNode);
      result.cumulativeDistances.push_back(currentDistance);

      const auto *neighbors = graph.getNeighbors(currentNode);
      if (!neighbors)
        continue;

      for (const auto &neighbor : *neighbors)
      {
        if (visited.find(neighbor.toNodeId) == visited.end())
        {
          const Edge *edge = graph.getEdge(neighbor.edgeId);
          if (!edge || !context.isEdgeAccessible(*edge))
            continue;

          double effectiveWeight = context.calculateEffectiveWeight(*edge);
          visited.insert(neighbor.toNodeId);
          queue.push({neighbor.toNodeId, currentDistance + effectiveWeight});
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
      const ProfileContext &context) const override
  {
    auto startTime = std::chrono::high_resolution_clock::now();

    PathResult result;
    result.algorithm = "BFS";
    result.pathExists = false;
    result.totalDistance = 0.0;

    std::unordered_set<int> visited;
    std::unordered_map<int, int> parent;
    std::unordered_map<int, double> distances;
    std::queue<int> queue;

    queue.push(startNodeId);
    visited.insert(startNodeId);
    parent[startNodeId] = -1;
    distances[startNodeId] = 0.0;

    bool found = false;

    while (!queue.empty() && !found)
    {
      int currentNode = queue.front();
      queue.pop();

      if (currentNode == endNodeId)
      {
        found = true;
        break;
      }

      const auto *neighbors = graph.getNeighbors(currentNode);
      if (!neighbors)
        continue;

      for (const auto &neighbor : *neighbors)
      {
        if (visited.find(neighbor.toNodeId) == visited.end())
        {
          const Edge *edge = graph.getEdge(neighbor.edgeId);
          if (!edge || !context.isEdgeAccessible(*edge))
            continue;

          double effectiveWeight = context.calculateEffectiveWeight(*edge);
          visited.insert(neighbor.toNodeId);
          parent[neighbor.toNodeId] = currentNode;
          distances[neighbor.toNodeId] = distances[currentNode] + effectiveWeight;
          queue.push(neighbor.toNodeId);
        }
      }
    }

    if (found)
    {
      // Reconstruct path
      result.pathExists = true;
      std::vector<int> reversePath;
      int current = endNodeId;

      while (current != -1)
      {
        reversePath.push_back(current);
        current = parent[current];
      }

      // Reverse to get correct order
      result.path = std::vector<int>(reversePath.rbegin(), reversePath.rend());

      // Calculate segment distances
      for (size_t i = 0; i < result.path.size() - 1; i++)
      {
        int from = result.path[i];
        int to = result.path[i + 1];
        double segmentDist = distances[to] - distances[from];
        result.segmentDistances.push_back(segmentDist);
      }

      result.totalDistance = distances[endNodeId];
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    result.executionTimeMicros = std::chrono::duration_cast<std::chrono::microseconds>(
                                      endTime - startTime)
                                      .count();

    return result;
  }

  std::string getName() const override { return "BFS"; }
};
