#pragma once

#include <crow.h>
#include "../../database/models/Edge.h"
#include "../../database/enums/EdgeType.h"
#include "../../database/enums/EdgeStatus.h"
#include "UpdateEdgeSchema.h"

class UpdateEdgeMapper
{
public:
  // Apply partial update to edge
  static void applyUpdate(Edge &edge, const UpdateEdgeRequest &request)
  {
    if (request.type.has_value())
    {
      EdgeType edgeType = edgeTypeFromString(request.type.value());
      edge.type = toInt(edgeType);
    }

    if (request.status.has_value())
    {
      EdgeStatus edgeStatus = edgeStatusFromString(request.status.value());
      edge.status = toInt(edgeStatus);
    }

    if (request.weight.has_value())
    {
      edge.weight = request.weight.value();
    }
  }

  // Convert edge to response
  static crow::json::wvalue toResponse(const Edge &edge)
  {
    crow::json::wvalue response;
    
    response["id"] = edge.id;
    response["type"] = toString(static_cast<EdgeType>(edge.type));
    response["status"] = toString(static_cast<EdgeStatus>(edge.status));
    response["weight"] = edge.weight;
    response["fromNodeId"] = edge.fromNodeId;
    response["toNodeId"] = edge.toNodeId;

    return response;
  }
};
