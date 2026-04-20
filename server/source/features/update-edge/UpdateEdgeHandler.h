#pragma once

#include <crow.h>
#include "../../database/ORM.h"
#include "../../core/dal/EdgeDao.h"
#include "UpdateEdgeSchema.h"
#include "UpdateEdgeMapper.h"

class UpdateEdgeHandler
{
private:
  Storage &storage;

public:
  UpdateEdgeHandler(Storage &storage) : storage(storage) {}

  crow::json::wvalue updateEdge(int edgeId, const crow::request &req)
  {
    auto body = crow::json::load(req.body);
    if (!body)
    {
      return crow::json::wvalue{{"error", "Invalid JSON"}};
    }

    UpdateEdgeRequest updateRequest;
    auto [isValid, errorMessage] = UpdateEdgeSchema::validate(body, updateRequest);
    if (!isValid)
    {
      return crow::json::wvalue{{"error", errorMessage}};
    }

    try
    {
      EdgeDao edgeDao(storage);
      Edge edge = edgeDao.getById(edgeId);
      
      UpdateEdgeMapper::applyUpdate(edge, updateRequest);
      edgeDao.update(edge);

      return UpdateEdgeMapper::toResponse(edge);
    }
    catch (const std::exception &e)
    {
      return crow::json::wvalue{{"error", e.what()}};
    }
  }
};
