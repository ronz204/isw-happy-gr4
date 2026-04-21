#pragma once

#include <crow.h>
#include "../../core/strategies/SearchStrategy.h"
#include "../../database/enums/NodeType.h"

class NavigateGraphMapper
{
public:
  // Convert SearchResponse to JSON response
  static crow::json::wvalue toResponse(const SearchResponse &searchResponse)
  {
    crow::json::wvalue response;

    response["success"] = searchResponse.success;
    response["algorithm"] = searchResponse.algorithm;
    response["distance"] = searchResponse.distance;
    response["time"] = searchResponse.time;

    if (searchResponse.success)
    {
      // Map path nodes to JSON array
      std::vector<crow::json::wvalue> pathArray;
      for (const auto &pathNode : searchResponse.path)
      {
        crow::json::wvalue node;
        node["code"] = pathNode.code;
        node["px"] = pathNode.px;
        node["py"] = pathNode.py;
        node["type"] = toString(static_cast<NodeType>(pathNode.type));
        pathArray.push_back(std::move(node));
      }
      response["path"] = std::move(pathArray);
    }
    else
    {
      response["path"] = std::vector<crow::json::wvalue>();
      response["message"] = "No path found between the specified nodes";
    }

    return response;
  }
};
