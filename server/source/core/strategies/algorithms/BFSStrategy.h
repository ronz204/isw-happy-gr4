#pragma once

#include "../SearchStrategy.h"
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <chrono>
#include <limits>

class BFSStrategy : public SearchStrategy
{
public:
  SearchResponse search(
      const Graph &graph,
      const Profile &profile,
      int startNodeId,
      int endNodeId) const override
  {
    SearchResponse result;
    result.algorithm = "BFS";

    // Start timing
    auto startTime = std::chrono::high_resolution_clock::now();

    // Validate start and end nodes exist
    if (!graph.getNode(startNodeId) || !graph.getNode(endNodeId))
    {
      auto endTime = std::chrono::high_resolution_clock::now();
      result.time = std::chrono::duration<double, std::milli>(endTime - startTime).count();
      return result;
    }

    // BFS data structures
    std::queue<int> queue;
    std::unordered_set<int> visited;
    std::unordered_map<int, int> parent;           // To reconstruct path
    std::unordered_map<int, double> distances;     // Accumulated distances

    // Initialize
    queue.push(startNodeId);
    visited.insert(startNodeId);
    parent[startNodeId] = -1; // Start node has no parent
    distances[startNodeId] = 0.0;

    bool found = false;

    // Perform BFS
    while (!queue.empty() && !found)
    {
      int currentNodeId = queue.front();
      queue.pop();

      // Check if we reached the target
      if (currentNodeId == endNodeId)
      {
        found = true;
        break;
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

          // Mark as visited and enqueue
          visited.insert(neighborId);
          parent[neighborId] = currentNodeId;
          distances[neighborId] = distances[currentNodeId] + edgeWeight;
          queue.push(neighborId);
        }
      }
    }

    // Reconstruct path if found
    if (found)
    {
      result.success = true;
      result.distance = distances[endNodeId];

      // Reconstruct path from end to start
      std::vector<int> reversePath;
      int current = endNodeId;
      while (current != -1)
      {
        reversePath.push_back(current);
        current = parent[current];
      }

      // Reverse to get path from start to end
      result.path = std::vector<int>(reversePath.rbegin(), reversePath.rend());
    }

    // End timing
    auto endTime = std::chrono::high_resolution_clock::now();
    result.time = std::chrono::duration<double, std::milli>(endTime - startTime).count();

    return result;
  }
};
