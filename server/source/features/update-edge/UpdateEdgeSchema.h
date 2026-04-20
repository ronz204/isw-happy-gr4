#pragma once

#include <crow.h>
#include <optional>
#include <string>
#include <vector>
#include "../../database/enums/EdgeType.h"
#include "../../database/enums/EdgeStatus.h"

struct UpdateEdgeRequest
{
  std::optional<std::string> type;
  std::optional<std::string> status;
  std::optional<double> weight;
};

class UpdateEdgeSchema
{
public:
  // Parse and validate request body
  static std::pair<bool, std::string> validate(const crow::json::rvalue &body, UpdateEdgeRequest &request)
  {
    // At least one field must be provided
    if (!body.has("type") && !body.has("status") && !body.has("weight"))
    {
      return {false, "At least one field (type, status, or weight) must be provided"};
    }

    // Validate type if provided
    if (body.has("type"))
    {
      if (body["type"].t() != crow::json::type::String)
      {
        return {false, "Field 'type' must be a string"};
      }

      std::string typeStr = body["type"].s();
      try
      {
        edgeTypeFromString(typeStr); // Validate it's a valid EdgeType
        request.type = typeStr;
      }
      catch (const std::invalid_argument &)
      {
        return {false, "Invalid edge type. Valid values: Hallway, Stairs, Ramp, Elevator, Outdoor, Bridge"};
      }
    }

    // Validate status if provided
    if (body.has("status"))
    {
      if (body["status"].t() != crow::json::type::String)
      {
        return {false, "Field 'status' must be a string"};
      }

      std::string statusStr = body["status"].s();
      try
      {
        edgeStatusFromString(statusStr); // Validate it's a valid EdgeStatus
        request.status = statusStr;
      }
      catch (const std::invalid_argument &)
      {
        return {false, "Invalid edge status. Valid values: Open, Closed"};
      }
    }

    // Validate weight if provided
    if (body.has("weight"))
    {
      if (body["weight"].t() != crow::json::type::Number)
      {
        return {false, "Field 'weight' must be a number"};
      }

      double weight = body["weight"].d();
      if (weight <= 0)
      {
        return {false, "Field 'weight' must be greater than 0"};
      }

      request.weight = weight;
    }

    return {true, ""};
  }
};
