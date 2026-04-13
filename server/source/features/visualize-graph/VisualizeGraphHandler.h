#pragma once

#include <crow.h>
#include "../../core/dal/NodeDao.h"
#include "../../core/dal/EdgeDao.h"
#include "../../database/ORM.h"
#include "VisualizeGraphMapper.h"

class VisualizeGraphHandler
{
private:
  Storage &storage;

public:
  VisualizeGraphHandler(Storage &storage) : storage(storage) {}

  crow::json::wvalue getGraph()
  {
    NodeDao nodeDao(storage);
    EdgeDao edgeDao(storage);

    auto nodes = nodeDao.getAll();
    auto edges = edgeDao.getAll();

    return VisualizeGraphMapper::toResponse(nodes, edges);
  }
};