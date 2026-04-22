#pragma once

#include <crow.h>
#include "../../database/ORM.h"
#include "../../core/dal/GraphLoader.h"
#include "../../core/dal/GraphDao.h"
#include "../../core/profiles/ProfileFactory.h"
#include "../../core/strategies/SearchContext.h"
#include "../../core/strategies/SearchFactory.h"
#include "NavigateGraphSchema.h"
#include "NavigateGraphMapper.h"

class NavigateGraphHandler
{
private:
  Storage &storage;

public:
  NavigateGraphHandler(Storage &storage) : storage(storage) {}

  crow::json::wvalue navigate(const crow::request &req)
  {
    auto body = crow::json::load(req.body);
    if (!body)
    {
      return crow::json::wvalue{{"error", "Invalid JSON"}};
    }

    NavigateGraphRequest request;
    auto [isValid, errorMessage] = NavigateGraphSchema::validate(body, request);
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

      SearchContext searchContext;
      try
      {
        auto strategy = SearchFactory::createStrategy(request.strategy);
        searchContext.setStrategy(std::move(strategy));
      }
      catch (const std::invalid_argument &)
      {
        return crow::json::wvalue{{"error", "Invalid strategy"}};
      }

      SearchResponse searchResponse = searchContext.executeSearch(
          *graph,
          *profile,
          request.startNodeId,
          request.endNodeId);

      return NavigateGraphMapper::toResponse(searchResponse);
    }
    catch (const std::exception &e)
    {
      return crow::json::wvalue{{"error", e.what()}};
    }
  }
};
