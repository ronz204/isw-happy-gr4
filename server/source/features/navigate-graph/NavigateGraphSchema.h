#pragma once

#include <crow.h>
#include <string>
#include "../../database/enums/ProfileType.h"

struct NavigateGraphRequest
{
  int startNodeId;
  int endNodeId;
  std::string profile;
  std::string strategy;
};

class NavigateGraphSchema
{
public:
  // Parse and validate request body
  static std::pair<bool, std::string> validate(const crow::json::rvalue &body, NavigateGraphRequest &request)
  {
    // Validate startNodeId
    if (!body.has("startNodeId"))
    {
      return {false, "Field 'startNodeId' is required"};
    }
    if (body["startNodeId"].t() != crow::json::type::Number)
    {
      return {false, "Field 'startNodeId' must be a number"};
    }
    request.startNodeId = body["startNodeId"].i();

    // Validate endNodeId
    if (!body.has("endNodeId"))
    {
      return {false, "Field 'endNodeId' is required"};
    }
    if (body["endNodeId"].t() != crow::json::type::Number)
    {
      return {false, "Field 'endNodeId' must be a number"};
    }
    request.endNodeId = body["endNodeId"].i();

    // Validate profile
    if (!body.has("profile"))
    {
      return {false, "Field 'profile' is required"};
    }
    if (body["profile"].t() != crow::json::type::String)
    {
      return {false, "Field 'profile' must be a string"};
    }
    std::string profileStr = body["profile"].s();
    try
    {
      profileTypeFromString(profileStr); // Validate it's a valid ProfileType
      request.profile = profileStr;
    }
    catch (const std::invalid_argument &)
    {
      return {false, "Invalid profile type. Valid values: Regular, NewStudent, Wheelchair"};
    }

    // Validate strategy
    if (!body.has("strategy"))
    {
      return {false, "Field 'strategy' is required"};
    }
    if (body["strategy"].t() != crow::json::type::String)
    {
      return {false, "Field 'strategy' must be a string"};
    }
    std::string strategyStr = body["strategy"].s();
    
    // Validate strategy is BFS or DFS
    if (strategyStr != "BFS" && strategyStr != "DFS")
    {
      return {false, "Invalid strategy. Valid values: BFS, DFS"};
    }
    request.strategy = strategyStr;

    return {true, ""};
  }
};
