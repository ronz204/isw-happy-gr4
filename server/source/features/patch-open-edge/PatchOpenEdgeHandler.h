#pragma once

#include <crow.h>
#include "../../core/dal/EdgeDao.h"
#include "../../database/ORM.h"
#include "../../database/enums/EdgeStatus.h"
#include "PatchOpenEdgeSchema.h"
#include "PatchOpenEdgeMapper.h"

class PatchOpenEdgeHandler
{
private:
  Storage &storage;

public:
  PatchOpenEdgeHandler(Storage &storage) : storage(storage) {}

  crow::json::wvalue openEdge(const std::string &edgeIdStr)
  {
    PatchOpenEdgeRequest request;
    auto [isValid, errorMessage] = PatchOpenEdgeSchema::validate(edgeIdStr, request);
    
    if (!isValid)
    {
      return crow::json::wvalue{{"error", errorMessage}};
    }

    EdgeDao edgeDao(storage);

    try
    {
      // Get the edge
      auto edge = edgeDao.getById(request.edgeId);
      
      // Update status to Open
      edge.status = static_cast<int>(EdgeStatus::Open);
      
      // Save the updated edge
      edgeDao.update(edge);

      return PatchOpenEdgeMapper::toResponse(edge);
    }
    catch (const std::system_error &e)
    {
      return crow::json::wvalue{{"error", "Edge not found"}};
    }
    catch (const std::exception &e)
    {
      return crow::json::wvalue{{"error", "Failed to open edge"}};
    }
  }
};
