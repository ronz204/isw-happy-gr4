#pragma once

#include <crow.h>
#include "../../core/response/PathResult.h"

class NavigateGraphMapper
{
public:
  static crow::json::wvalue toResponse(const PathResult &result)
  {
    crow::json::wvalue response;

    response["pathExists"] = result.pathExists;
    response["algorithm"] = result.algorithm;
    response["executionTimeMicros"] = result.executionTimeMicros;
    response["totalDistance"] = result.totalDistance;

    // Map path (node IDs)
    response["path"] = crow::json::wvalue::list();
    for (size_t i = 0; i < result.path.size(); i++)
    {
      response["path"][i] = result.path[i];
    }

    // Map segment distances
    response["segmentDistances"] = crow::json::wvalue::list();
    for (size_t i = 0; i < result.segmentDistances.size(); i++)
    {
      response["segmentDistances"][i] = result.segmentDistances[i];
    }

    return response;
  }
};
