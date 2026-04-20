#pragma once

#include "Node.h"
#include "Edge.h"

#include <vector>
#include <unordered_map>

struct GraphEdge
{
  int toNodeId;
  double weight;
  int edgeId;
};

class Graph
{
private:
  std::unordered_map<int, Node> nodes;
  std::unordered_map<int, std::vector<GraphEdge>> adjList;
  std::unordered_map<int, Edge> edges;

public:
  void addNode(const Node &node)
  {
    nodes[node.id] = node;
  };

  void addEdge(const Edge &edge)
  {
    edges[edge.id] = edge;
    adjList[edge.fromNodeId].push_back({edge.toNodeId, edge.weight, edge.id});
    adjList[edge.toNodeId].push_back({edge.fromNodeId, edge.weight, edge.id});
  };

  // Getters
  const Node *getNode(int id) const
  {
    auto it = nodes.find(id);
    return it != nodes.end() ? &it->second : nullptr;
  }

  const Edge *getEdge(int id) const
  {
    auto it = edges.find(id);
    return it != edges.end() ? &it->second : nullptr;
  }

  const std::vector<GraphEdge> *getNeighbors(int nodeId) const
  {
    auto it = adjList.find(nodeId);
    return it != adjList.end() ? &it->second : nullptr;
  }

  const std::unordered_map<int, Node> &getAllNodes() const
  {
    return nodes;
  }

  std::vector<int> getAllNodeIds() const
  {
    std::vector<int> ids;
    ids.reserve(nodes.size());
    for (const auto &pair : nodes)
    {
      ids.push_back(pair.first);
    }
    return ids;
  }

  int getNodeCount() const
  {
    return nodes.size();
  }

  int getEdgeCount() const
  {
    return edges.size();
  }
};
