#pragma once

#include "./database/models/Node.h"
#include "./database/models/Edge.h"
#include "./database/models/Graph.h"
#include "./database/ORM.h"

class GraphLoader
{
public:
  static Graph loadFromDB(Storage &storage)
  {
    Graph graph;

    auto nodes = storage.get_all<Node>();
    for (const auto &node : nodes)
    {
      graph.addNode(node);
    }

    auto edges = storage.get_all<Edge>();
    for (const auto &edge : edges)
    {
      graph.addEdge(edge);
    }

    return graph;
  }
};
