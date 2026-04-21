#pragma once

#include "../../database/models/Graph.h"
#include "../../database/ORM.h"
#include "NodeDao.h"
#include "EdgeDao.h"
#include <memory>

class GraphLoader
{
private:
  Storage &storage;
  NodeDao nodeDao;
  EdgeDao edgeDao;

public:
  GraphLoader(Storage &storage)
      : storage(storage),
        nodeDao(storage),
        edgeDao(storage) {}

  std::unique_ptr<Graph> loadGraph()
  {
    auto graph = std::make_unique<Graph>();

    // Load all nodes
    auto nodes = nodeDao.getAll();
    for (const auto &node : nodes)
    {
      graph->addNode(node);
    }

    // Load all edges
    auto edges = edgeDao.getAll();
    for (const auto &edge : edges)
    {
      graph->addEdge(edge);
    }

    return graph;
  }
};
