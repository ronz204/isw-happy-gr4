#pragma once

#include "SearchStrategy.h"
#include <unordered_set>
#include <chrono>

class DFSStrategy : public SearchStrategy
{
private:
  void dfsRecursive(
      const Graph &graph,
      int currentNode,
      std::unordered_set<int> &visited,
      std::vector<int> &visitedNodes,
      std::vector<double> &cumulativeDistances,
      double currentDistance,
      const ProfileContext &context) const
  {
    visited.insert(currentNode);
    visitedNodes.push_back(currentNode);
    cumulativeDistances.push_back(currentDistance);

    const auto *neighbors = graph.getNeighbors(currentNode);
    if (!neighbors)
      return;

    for (const auto &neighbor : *neighbors)
    {
      if (visited.find(neighbor.toNodeId) == visited.end())
      {
        const Edge *edge = graph.getEdge(neighbor.edgeId);
        if (!edge || !context.isEdgeAccessible(*edge))
          continue;

        double effectiveWeight = context.calculateEffectiveWeight(*edge);
        dfsRecursive(graph, neighbor.toNodeId, visited, visitedNodes,
                     cumulativeDistances, currentDistance + effectiveWeight, context);
      }
    }
  }

  bool dfsPathRecursive(
      const Graph &graph,
      int current,
      int destination,
      std::unordered_set<int> &visited,
      std::vector<int> &path,
      std::vector<double> &segmentDistances,
      double &totalDistance,
      const ProfileContext &context) const
  {
    visited.insert(current);
    path.push_back(current);

    if (current == destination)
    {
      return true;
    }

    const auto *neighbors = graph.getNeighbors(current);
    if (!neighbors)
    {
      path.pop_back();
      visited.erase(current);
      return false;
    }

    for (const auto &neighbor : *neighbors)
    {
      if (visited.find(neighbor.toNodeId) == visited.end())
      {
        const Edge *edge = graph.getEdge(neighbor.edgeId);
        if (!edge || !context.isEdgeAccessible(*edge))
          continue;

        double effectiveWeight = context.calculateEffectiveWeight(*edge);
        segmentDistances.push_back(effectiveWeight);
        totalDistance += effectiveWeight;

        if (dfsPathRecursive(graph, neighbor.toNodeId, destination, visited,
                             path, segmentDistances, totalDistance, context))
        {
          return true;
        }

        // Backtrack
        segmentDistances.pop_back();
        totalDistance -= effectiveWeight;
      }
    }

    path.pop_back();
    visited.erase(current);
    return false;
  }

public:
  TraversalResult traverse(
      const Graph &graph,
      int startNodeId,
      const ProfileContext &context) const override
  {
    auto startTime = std::chrono::high_resolution_clock::now();

    TraversalResult result;
    result.algorithm = "DFS";

    std::unordered_set<int> visited;
    dfsRecursive(graph, startNodeId, visited, result.visitedNodes,
                 result.cumulativeDistances, 0.0, context);

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
    result.algorithm = "DFS";
    result.totalDistance = 0.0;

    std::unordered_set<int> visited;
    result.pathExists = dfsPathRecursive(graph, startNodeId, endNodeId, visited,
                                         result.path, result.segmentDistances,
                                         result.totalDistance, context);

    auto endTime = std::chrono::high_resolution_clock::now();
    result.executionTimeMicros = std::chrono::duration_cast<std::chrono::microseconds>(
                                      endTime - startTime)
                                      .count();

    return result;
  }

  std::string getName() const override { return "DFS"; }
};
