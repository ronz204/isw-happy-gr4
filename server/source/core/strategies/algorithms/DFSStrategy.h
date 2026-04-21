#pragma once

#include "../SearchStrategy.h"
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <chrono>
#include <limits>

class DFSStrategy : public SearchStrategy
{
public:
  SearchResponse search(
      const Graph &graph,
      const Profile &profile,
      int startNodeId,
      int endNodeId) const override
  {
    SearchResponse result;
    result.algorithm = "DFS";

    // Start timing
    auto startTime = std::chrono::high_resolution_clock::now();

    // Validate start and end nodes exist
    if (!graph.getNode(startNodeId) || !graph.getNode(endNodeId))
    {
      auto endTime = std::chrono::high_resolution_clock::now();
      result.time = std::chrono::duration<double, std::milli>(endTime - startTime).count();
      return result;
    }

    std::unordered_set<int> visited;
    std::vector<int> pathIds;
    double distance = 0.0;

    // Perform DFS
    if (dfsRecursive(graph, profile, startNodeId, endNodeId, visited, pathIds, distance))
    {
      result.success = true;
      result.path = SearchResponse::convertToPathNodes(pathIds, graph);
      result.distance = distance;
    }

    // End timing
    auto endTime = std::chrono::high_resolution_clock::now();
    result.time = std::chrono::duration<double, std::milli>(endTime - startTime).count();

    return result;
  }

private:
  bool dfsRecursive(
      const Graph &graph,
      const Profile &profile,
      int currentNodeId,
      int targetNodeId,
      std::unordered_set<int> &visited,
      std::vector<int> &path,
      double &distance) const
  {
    // Mark as visited
    visited.insert(currentNodeId);
    path.push_back(currentNodeId);

    // Check if we reached the target
    if (currentNodeId == targetNodeId)
    {
      return true;
    }

    // Explore all edges from current node (graph is bidirectional)
    const std::vector<Edge> *edges = graph.getEdges(currentNodeId);
    if (edges)
    {
      for (const Edge &edge : *edges)
      {
        int neighborId = edge.toNodeId;

        // Skip if already visited
        if (visited.count(neighborId))
          continue;

        // Skip if profile cannot use this edge
        if (!profile.canUse(edge))
          continue;

        // Get edge weight according to profile
        double edgeWeight = profile.getWeight(edge);

        // Skip if edge is not usable (infinite weight)
        if (edgeWeight == std::numeric_limits<double>::infinity())
          continue;

        // Recursively search
        distance += edgeWeight;
        if (dfsRecursive(graph, profile, neighborId, targetNodeId, visited, path, distance))
        {
          return true;
        }
        distance -= edgeWeight;
      }
    }

    // Backtrack
    path.pop_back();
    return false;
  }
};
