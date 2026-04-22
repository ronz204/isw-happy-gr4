#pragma once

#include <crow.h>
#include "../../core/dal/NodeDao.h"
#include "../../core/dal/EdgeDao.h"
#include "../../database/ORM.h"
#include "GetNodesByFloorSchema.h"
#include "GetNodesByFloorMapper.h"

class GetNodesByFloorHandler
{
private:
  Storage &storage;

public:
  GetNodesByFloorHandler(Storage &storage) : storage(storage) {}

  crow::json::wvalue getByFloor(const std::string &floorStr)
  {
    GetNodesByFloorRequest request;
    auto [isValid, errorMessage] = GetNodesByFloorSchema::validate(floorStr, request);
    
    if (!isValid)
    {
      return crow::json::wvalue{{"error", errorMessage}};
    }

    NodeDao nodeDao(storage);
    EdgeDao edgeDao(storage);

    auto nodes = nodeDao.getByFloor(request.floor);
    auto edges = edgeDao.getByFloor(request.floor);

    return GetNodesByFloorMapper::toResponse(nodes, edges);
  }
};