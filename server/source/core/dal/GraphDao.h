#pragma once

#include "../../database/models/Graph.h"
#include "../../database/models/Node.h"
#include "../../database/models/Edge.h"
#include <vector>
#include <optional>

class GraphDao
{
private:
  Graph &graph;

public:
  GraphDao(Graph &graph) : graph(graph) {}

  std::optional<Node> getNodeById(int nodeId) const
  {
    const Node *node = graph.getNode(nodeId);
    if (node)
    {
      return *node;
    }
    return std::nullopt;
  }

  std::vector<Node> getAllNodes() const
  {
    std::vector<Node> result;
    const auto &nodes = graph.getNodes();
    result.reserve(nodes.size());

    for (const auto &[id, node] : nodes)
    {
      result.push_back(node);
    }

    return result;
  }

  std::vector<Edge> getEdges(int nodeId) const
  {
    const auto *edges = graph.getEdges(nodeId);
    if (edges)
    {
      return *edges;
    }
    return {};
  }

  bool nodeExists(int nodeId) const
  {
    return graph.getNode(nodeId) != nullptr;
  }
};
