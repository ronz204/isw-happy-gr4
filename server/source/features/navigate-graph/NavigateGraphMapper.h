#pragma once

#include <crow.h>
#include "../../core/strategies/SearchResponse.h"
#include "../../database/enums/NodeType.h"

class NavigateGraphMapper
{
public:
  static crow::json::wvalue toResponse(const SearchResponse &searchResponse)
  {
    crow::json::wvalue response;

    response["success"] = searchResponse.success;
    response["algorithm"] = searchResponse.algorithm;
    response["distance"] = searchResponse.distance;
    response["time"] = searchResponse.time;

    if (searchResponse.success)
    {
      response["path"] = crow::json::wvalue::list();
      auto &pathArray = response["path"];
      
      for (size_t i = 0; i < searchResponse.path.size(); i++)
      {
        const auto &pathNode = searchResponse.path[i];
        pathArray[i]["code"] = pathNode.code;
        pathArray[i]["px"] = pathNode.px;
        pathArray[i]["py"] = pathNode.py;
        pathArray[i]["type"] = toString(static_cast<NodeType>(pathNode.type));
      }
    }
    else
    {
      response["path"] = crow::json::wvalue::list();
      response["message"] = "No path found between the specified nodes";
    }

    return response;
  }
};
