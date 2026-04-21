#pragma once

#include <unordered_map>
#include <vector>
#include <memory>
#include "Node.h"
#include "Edge.h"

class Graph
{
private:
  std::unordered_map<int, Node> nodes;
  std::unordered_map<int, std::vector<Edge>> adjacencyList;

public:
  Graph() = default;

  void addNode(const Node &node)
  {
    nodes[node.id] = node;
    if (adjacencyList.find(node.id) == adjacencyList.end())
    {
      adjacencyList[node.id] = std::vector<Edge>();
    }
  }

  void addEdge(const Edge &edge)
  {
    // Add edge in forward direction
    adjacencyList[edge.fromNodeId].push_back(edge);
    
    // Add edge in reverse direction for undirected graph
    Edge reverseEdge = edge;
    reverseEdge.fromNodeId = edge.toNodeId;
    reverseEdge.toNodeId = edge.fromNodeId;
    adjacencyList[edge.toNodeId].push_back(reverseEdge);
  }

  const std::unordered_map<int, Node> &getNodes() const
  {
    return nodes;
  }

  const std::unordered_map<int, std::vector<Edge>> &getAdjacencyList() const
  {
    return adjacencyList;
  }

  const Node *getNode(int nodeId) const
  {
    auto it = nodes.find(nodeId);
    return (it != nodes.end()) ? &it->second : nullptr;
  }

  const std::vector<Edge> *getEdges(int nodeId) const
  {
    auto it = adjacencyList.find(nodeId);
    return (it != adjacencyList.end()) ? &it->second : nullptr;
  }
};
