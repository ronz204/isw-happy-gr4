#pragma once

#include <crow.h>
#include "../../core/dal/NodeDao.h"
#include "../../core/dal/EdgeDao.h"
#include "../../database/ORM.h"
#include "GetGraphFullMapper.h"

class GetGraphFullHandler
{
private:
  Storage &storage;

public:
  GetGraphFullHandler(Storage &storage) : storage(storage) {}

  crow::json::wvalue getFullGraph()
  {
    NodeDao nodeDao(storage);
    EdgeDao edgeDao(storage);

    auto nodes = nodeDao.getAll();
    auto edges = edgeDao.getAll();

    return GetGraphFullMapper::toResponse(nodes, edges);
  }
};