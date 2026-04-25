#pragma once

#include <crow.h>
#include <string>
#include "../../database/enums/ProfileType.h"

struct GetPerformanceRequest
{
  int startNodeId;
  int endNodeId;
  std::string profile;
};

class GetPerformanceSchema
{
public:
  static std::pair<bool, std::string> validate(const crow::json::rvalue &body, GetPerformanceRequest &request)
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
      profileTypeFromString(profileStr);
      request.profile = profileStr;
    }
    catch (const std::invalid_argument &)
    {
      return {false, "Invalid profile type. Valid values: Regular, NewStudent, Wheelchair"};
    }

    return {true, ""};
  }
};
