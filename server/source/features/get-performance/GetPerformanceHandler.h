#pragma once

#include <crow.h>
#include <vector>
#include "../../database/ORM.h"
#include "../../core/dal/GraphLoader.h"
#include "../../core/dal/GraphDao.h"
#include "../../core/profiles/ProfileFactory.h"
#include "../../core/strategies/SearchContext.h"
#include "../../core/strategies/SearchFactory.h"
#include "../../core/strategies/SearchResponse.h"
#include "GetPerformanceSchema.h"
#include "GetPerformanceMapper.h"

class GetPerformanceHandler
{
private:
  Storage &storage;

  static constexpr const char *STRATEGIES[] = {"BFS", "DFS", "Dijkstra"};

public:
  GetPerformanceHandler(Storage &storage) : storage(storage) {}

  crow::json::wvalue handle(const crow::request &req)
  {
    auto body = crow::json::load(req.body);
    if (!body)
    {
      return crow::json::wvalue{{"error", "Invalid JSON"}};
    }

    GetPerformanceRequest request;
    auto [isValid, errorMessage] = GetPerformanceSchema::validate(body, request);
    if (!isValid)
    {
      return crow::json::wvalue{{"error", errorMessage}};
    }

    try
    {
      GraphLoader graphLoader(storage);
      auto graph = graphLoader.loadGraph();

      GraphDao graphDao(*graph);
      if (!graphDao.nodeExists(request.startNodeId))
      {
        return crow::json::wvalue{{"error", "Start node not found"}};
      }
      if (!graphDao.nodeExists(request.endNodeId))
      {
        return crow::json::wvalue{{"error", "End node not found"}};
      }

      auto profile = ProfileFactory::createProfile(request.profile);

      std::vector<SearchResponse> results;
      results.reserve(3);

      for (const char *strategyName : STRATEGIES)
      {
        SearchContext searchContext(SearchFactory::createStrategy(strategyName));
        results.push_back(searchContext.executeSearch(
            *graph,
            *profile,
            request.startNodeId,
            request.endNodeId));
      }

      return GetPerformanceMapper::toResponse(results);
    }
    catch (const std::exception &e)
    {
      return crow::json::wvalue{{"error", e.what()}};
    }
  }
};
