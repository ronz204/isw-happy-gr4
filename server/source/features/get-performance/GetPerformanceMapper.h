#pragma once

#include <crow.h>
#include <vector>
#include "../../core/strategies/SearchResponse.h"

class GetPerformanceMapper
{
public:
  static crow::json::wvalue toResponse(const std::vector<SearchResponse> &results)
  {
    crow::json::wvalue response;
    response["results"] = crow::json::wvalue::list();

    for (size_t i = 0; i < results.size(); i++)
    {
      const auto &r = results[i];
      response["results"][i]["algorithm"] = r.algorithm;
      response["results"][i]["success"] = r.success;
      response["results"][i]["distance"] = r.distance;
      response["results"][i]["time"] = r.time;
    }

    return response;
  }
};
