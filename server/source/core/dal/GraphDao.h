#pragma once

#include "../../database/models/Graph.h"
#include "../../database/enums/EdgeStatus.h"
#include "../strategies/SearchStrategy.h"
#include "../strategies/DFSStrategy.h"
#include "../profiles/Profile.h"
#include "../response/TraversalResult.h"
#include "../response/PathResult.h"
#include <memory>
#include <unordered_set>
#include <queue>

class GraphDao
{
private:
  const Graph &graph;

  // Check if edge is open (not blocked/closed)
  bool isEdgeOpen(const Edge *edge) const
  {
    if (!edge)
      return false;
    
    EdgeStatus status = static_cast<EdgeStatus>(edge->status);
    return status == EdgeStatus::Open;
  }

  void dfsConnectivityHelper(int node, std::unordered_set<int> &visited) const
  {
    visited.insert(node);

    const auto *neighbors = graph.getNeighbors(node);
    if (!neighbors)
      return;

    for (const auto &neighbor : *neighbors)
    {
      if (visited.find(neighbor.toNodeId) == visited.end())
      {
        // Only traverse through open edges
        const Edge *edge = graph.getEdge(neighbor.edgeId);
        if (!isEdgeOpen(edge))
          continue;

        dfsConnectivityHelper(neighbor.toNodeId, visited);
      }
    }
  }

public:
  GraphDao(const Graph &graph) : graph(graph) {}

  // Check if graph is fully connected
  bool isConnected() const
  {
    auto nodeIds = graph.getAllNodeIds();
    if (nodeIds.empty())
      return true;

    std::unordered_set<int> visited;
    dfsConnectivityHelper(nodeIds[0], visited);

    return visited.size() == nodeIds.size();
  }

  // Check if path exists between two nodes
  bool hasPath(int startId, int endId, const Profile &profile) const
  {
    if (startId == endId)
      return true;

    std::unordered_set<int> visited;
    std::queue<int> queue;

    queue.push(startId);
    visited.insert(startId);

    while (!queue.empty())
    {
      int current = queue.front();
      queue.pop();

      if (current == endId)
        return true;

      const auto *neighbors = graph.getNeighbors(current);
      if (!neighbors)
        continue;

      for (const auto &neighbor : *neighbors)
      {
        if (visited.find(neighbor.toNodeId) == visited.end())
        {
          const Edge *edge = graph.getEdge(neighbor.edgeId);
          if (!edge || !profile.isEdgeAccessible(*edge))
            continue;

          visited.insert(neighbor.toNodeId);
          queue.push(neighbor.toNodeId);
        }
      }
    }

    return false;
  }

  // Perform traversal using a strategy
  TraversalResult performTraversal(
      int startNodeId,
      const SearchStrategy &strategy,
      const Profile &profile) const
  {
    return strategy.traverse(graph, startNodeId, profile);
  }

  // Find path using a strategy
  PathResult findPath(
      int startNodeId,
      int endNodeId,
      const SearchStrategy &strategy,
      const Profile &profile) const
  {
    return strategy.findPath(graph, startNodeId, endNodeId, profile);
  }

  // Get node count
  int getNodeCount() const
  {
    return graph.getNodeCount();
  }

  // Get edge count
  int getEdgeCount() const
  {
    return graph.getEdgeCount();
  }

  // Get isolated nodes (nodes with no connections)
  std::vector<int> getIsolatedNodes() const
  {
    std::vector<int> isolated;
    auto nodeIds = graph.getAllNodeIds();

    for (int nodeId : nodeIds)
    {
      const auto *neighbors = graph.getNeighbors(nodeId);
      if (!neighbors || neighbors->empty())
      {
        isolated.push_back(nodeId);
      }
    }

    return isolated;
  }
};
