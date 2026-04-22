#pragma once

#include <crow.h>
#include "../../database/models/Edge.h"
#include "../../database/enums/EdgeType.h"
#include "../../database/enums/EdgeStatus.h"

class PatchCloseEdgeMapper
{
public:
  static crow::json::wvalue toResponse(const Edge &edge)
  {
    crow::json::wvalue response;
    
    response["id"] = edge.id;
    response["type"] = toString(static_cast<EdgeType>(edge.type));
    response["floor"] = edge.floor;
    response["status"] = toString(static_cast<EdgeStatus>(edge.status));
    response["weight"] = edge.weight;
    response["fromNodeId"] = edge.fromNodeId;
    response["toNodeId"] = edge.toNodeId;
    response["message"] = "Edge closed successfully";

    return response;
  }
};