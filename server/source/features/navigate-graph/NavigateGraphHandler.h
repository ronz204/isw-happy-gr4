#pragma once

#include <crow.h>
#include "../../database/ORM.h"
#include "../../core/dal/GraphLoader.h"
#include "../../core/dal/GraphDao.h"
#include "../../core/profiles/ProfileFactory.h"
#include "../../core/strategies/SearchContext.h"
#include "../../core/strategies/algorithms/BFSStrategy.h"
#include "../../core/strategies/algorithms/DFSStrategy.h"
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

    NavigateGraphRequest navRequest;
    auto [isValid, errorMessage] = NavigateGraphSchema::validate(body, navRequest);
    if (!isValid)
    {
      return crow::json::wvalue{{"error", errorMessage}};
    }

    try
    {
      // Load graph from database
      GraphLoader graphLoader(storage);
      auto graph = graphLoader.loadGraph();

      // Validate that start and end nodes exist
      GraphDao graphDao(*graph);
      if (!graphDao.nodeExists(navRequest.startNodeId))
      {
        return crow::json::wvalue{{"error", "Start node not found"}};
      }
      if (!graphDao.nodeExists(navRequest.endNodeId))
      {
        return crow::json::wvalue{{"error", "End node not found"}};
      }

      // Create profile based on request
      auto profile = ProfileFactory::createProfile(navRequest.profile);

      // Create strategy based on request
      SearchContext searchContext;
      if (navRequest.strategy == "BFS")
      {
        searchContext.setStrategy(std::make_unique<BFSStrategy>());
      }
      else if (navRequest.strategy == "DFS")
      {
        searchContext.setStrategy(std::make_unique<DFSStrategy>());
      }
      else
      {
        return crow::json::wvalue{{"error", "Invalid strategy"}};
      }

      // Execute search
      SearchResponse searchResponse = searchContext.executeSearch(
          *graph,
          *profile,
          navRequest.startNodeId,
          navRequest.endNodeId);

      // Map response to JSON
      return NavigateGraphMapper::toResponse(searchResponse);
    }
    catch (const std::exception &e)
    {
      return crow::json::wvalue{{"error", e.what()}};
    }
  }
};
