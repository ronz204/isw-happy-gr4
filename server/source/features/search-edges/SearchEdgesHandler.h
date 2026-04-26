#pragma once

#include <crow.h>
#include "../../core/dal/EdgeDao.h"
#include "../../database/ORM.h"
#include "SearchEdgesSchema.h"
#include "SearchEdgesMapper.h"

class SearchEdgesHandler
{
private:
  Storage &storage;

public:
  SearchEdgesHandler(Storage &storage) : storage(storage) {}

  crow::json::wvalue searchEdges(const crow::request &req)
  {
    SearchEdgesRequest request;
    auto [isValid, errorMessage] = SearchEdgesSchema::validate(req, request);
    
    if (!isValid)
    {
      return crow::json::wvalue{{"error", errorMessage}};
    }

    EdgeDao edgeDao(storage);

    try
    {
      auto edges = edgeDao.findByNodes(request.fromNodeId, request.toNodeId);
      return SearchEdgesMapper::toResponse(edges);
    }
    catch (const std::exception &e)
    {
      return crow::json::wvalue{{"error", "Failed to search edges"}};
    }
  }
};
