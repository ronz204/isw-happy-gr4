#pragma once

#include "Node.h"
#include "Edge.h"

#include <vector>
#include <unordered_map>

struct GraphEdge
{
  int toNodeId;
  double weight;
};

class Graph
{
private:
  std::unordered_map<int, Node> nodes;
  std::unordered_map<int, std::vector<GraphEdge>> adjList;

public:
  void addNode(const Node &node)
  {
    nodes[node.id] = node;
  };

  void addEdge(const Edge &edge)
  {
    adjList[edge.fromNodeId].push_back({edge.toNodeId, edge.weight});
    adjList[edge.toNodeId].push_back({edge.fromNodeId, edge.weight});
  };
};
