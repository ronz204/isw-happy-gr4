#pragma once

#include <crow.h>
#include "../../core/dal/EdgeDao.h"
#include "../../database/ORM.h"
#include "../../database/enums/EdgeStatus.h"
#include "PatchCloseEdgeSchema.h"
#include "PatchCloseEdgeMapper.h"

class PatchCloseEdgeHandler
{
private:
  Storage &storage;

public:
  PatchCloseEdgeHandler(Storage &storage) : storage(storage) {}

  crow::json::wvalue closeEdge(const std::string &edgeIdStr)
  {
    PatchCloseEdgeRequest request;
    auto [isValid, errorMessage] = PatchCloseEdgeSchema::validate(edgeIdStr, request);
    
    if (!isValid)
    {
      return crow::json::wvalue{{"error", errorMessage}};
    }

    EdgeDao edgeDao(storage);

    try
    {
      // Get the edge
      auto edge = edgeDao.getById(request.edgeId);
      
      // Update status to Closed
      edge.status = static_cast<int>(EdgeStatus::Closed);
      
      // Save the updated edge
      edgeDao.update(edge);

      return PatchCloseEdgeMapper::toResponse(edge);
    }
    catch (const std::system_error &e)
    {
      return crow::json::wvalue{{"error", "Edge not found"}};
    }
    catch (const std::exception &e)
    {
      return crow::json::wvalue{{"error", "Failed to close edge"}};
    }
  }
};