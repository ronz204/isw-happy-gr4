#pragma once

#include "../SearchStrategy.h"
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
#include <chrono>
#include <limits>

class DijkstraStrategy : public SearchStrategy
{
public:
  SearchResponse search(
      const Graph &graph,
      const Profile &profile,
      int startNodeId,
      int endNodeId) const override
  {
    SearchResponse result;
    result.algorithm = "Dijkstra";

    // Start timing
    auto startTime = std::chrono::high_resolution_clock::now();

    // Validate start and end nodes exist
    if (!graph.getNode(startNodeId) || !graph.getNode(endNodeId))
    {
      auto endTime = std::chrono::high_resolution_clock::now();
      result.time = std::chrono::duration<double, std::milli>(endTime - startTime).count();
      return result;
    }

    // Min-heap: (cost, nodeId)
    using Entry = std::pair<double, int>;
    std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> pq;

    std::unordered_map<int, double> dist;
    std::unordered_map<int, int> parent;

    // Initialize
    dist[startNodeId] = 0.0;
    parent[startNodeId] = -1;
    pq.push({0.0, startNodeId});

    while (!pq.empty())
    {
      auto [currentDist, currentNodeId] = pq.top();
      pq.pop();

      // Skip stale entries
      if (currentDist > dist[currentNodeId])
        continue;

      // Stop early if target reached
      if (currentNodeId == endNodeId)
        break;

      // Explore neighbors
      const std::vector<Edge> *edges = graph.getEdges(currentNodeId);
      if (!edges)
        continue;

      for (const Edge &edge : *edges)
      {
        int neighborId = edge.toNodeId;

        // Skip if profile cannot use this edge
        if (!profile.canUse(edge))
          continue;

        double edgeWeight = profile.getWeight(edge);

        // Skip unusable edges
        if (edgeWeight == std::numeric_limits<double>::infinity())
          continue;

        double newDist = currentDist + edgeWeight;

        // Relax edge
        auto it = dist.find(neighborId);
        if (it == dist.end() || newDist < it->second)
        {
          dist[neighborId] = newDist;
          parent[neighborId] = currentNodeId;
          pq.push({newDist, neighborId});
        }
      }
    }

    // Reconstruct path if found
    if (dist.count(endNodeId))
    {
      result.success = true;
      result.distance = dist[endNodeId];

      std::vector<int> reversePathIds;
      int current = endNodeId;
      while (current != -1)
      {
        reversePathIds.push_back(current);
        current = parent[current];
      }

      std::vector<int> pathIds(reversePathIds.rbegin(), reversePathIds.rend());
      result.path = SearchResponse::convertToPathNodes(pathIds, graph);
    }

    // End timing
    auto endTime = std::chrono::high_resolution_clock::now();
    result.time = std::chrono::duration<double, std::milli>(endTime - startTime).count();

    return result;
  }
};
