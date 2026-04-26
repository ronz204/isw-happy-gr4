#pragma once

#include <crow.h>
#include <vector>
#include "../../database/models/Edge.h"
#include "../../database/enums/EdgeType.h"
#include "../../database/enums/EdgeStatus.h"

class SearchEdgesMapper
{
public:
  static crow::json::wvalue toResponse(const std::vector<Edge> &edges)
  {
    crow::json::wvalue response;
    
    if (edges.empty())
    {
      response["found"] = false;
      response["message"] = "No edge found with the specified node IDs";
      response["edge"] = nullptr;
    }
    else
    {
      // Return the first match (should typically be only one)
      const Edge &edge = edges[0];
      
      response["found"] = true;
      response["message"] = "Edge found successfully";
      
      crow::json::wvalue edgeData;
      edgeData["id"] = edge.id;
      edgeData["type"] = toString(static_cast<EdgeType>(edge.type));
      edgeData["floor"] = edge.floor;
      edgeData["status"] = toString(static_cast<EdgeStatus>(edge.status));
      edgeData["weight"] = edge.weight;
      edgeData["fromNodeId"] = edge.fromNodeId;
      edgeData["toNodeId"] = edge.toNodeId;
      
      response["edge"] = std::move(edgeData);
    }

    return response;
  }
};
