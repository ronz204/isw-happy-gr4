#pragma once

#include <crow.h>
#include <memory>
#include "../../database/ORM.h"
#include "../../helpers/GraphLoader.h"
#include "../../core/dal/GraphDao.h"
#include "../../core/profiles/ProfileContext.h"
#include "../../core/strategies/DFSStrategy.h"
#include "../../core/strategies/BFSStrategy.h"
#include "../../core/strategies/DijkstraStrategy.h"
#include "../../database/enums/UserProfile.h"
#include "NavigateGraphMapper.h"

class NavigateGraphHandler
{
private:
  Storage &storage;

public:
  NavigateGraphHandler(Storage &storage) : storage(storage) {}

  crow::json::wvalue findPath(const crow::request &req)
  {
    auto body = crow::json::load(req.body);
    if (!body)
    {
      return crow::json::wvalue{{"error", "Invalid JSON"}};
    }

    // Parse request parameters
    int startNodeId = body["startNodeId"].i();
    int endNodeId = body["endNodeId"].i();
    std::string userProfileStr = body["userProfile"].s();
    std::string algorithmStr = body["algorithm"].s();

    // Load graph from database
    Graph graph = GraphLoader::loadFromDB(storage);

    // Create profile context
    UserProfile profile = userProfileFromString(userProfileStr);
    ProfileContext context(profile);

    // Select search strategy
    std::unique_ptr<SearchStrategy> strategy;
    if (algorithmStr == "DFS")
    {
      strategy = std::make_unique<DFSStrategy>();
    }
    else if (algorithmStr == "BFS")
    {
      strategy = std::make_unique<BFSStrategy>();
    }
    else if (algorithmStr == "Dijkstra")
    {
      strategy = std::make_unique<DijkstraStrategy>();
    }
    else
    {
      return crow::json::wvalue{{"error", "Invalid algorithm. Use 'DFS', 'BFS', or 'Dijkstra'"}};
    }

    // Use GraphDao to find path
    GraphDao graphDao(graph);
    PathResult result = graphDao.findPath(startNodeId, endNodeId, *strategy, context);

    // Return mapped response with node details
    return NavigateGraphMapper::toResponse(result, graph);
  }
};
