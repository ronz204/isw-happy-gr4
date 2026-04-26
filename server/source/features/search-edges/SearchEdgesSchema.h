#pragma once

#include <crow.h>
#include <string>

struct SearchEdgesRequest
{
  int fromNodeId;
  int toNodeId;
};

class SearchEdgesSchema
{
public:
  // Validate search edges request from query parameters
  static std::pair<bool, std::string> validate(const crow::request &req, SearchEdgesRequest &request)
  {
    auto fromNodeIdParam = req.url_params.get("fromNodeId");
    auto toNodeIdParam = req.url_params.get("toNodeId");

    if (!fromNodeIdParam || !toNodeIdParam)
    {
      return {false, "Missing required parameters: fromNodeId and toNodeId"};
    }

    try
    {
      request.fromNodeId = std::stoi(fromNodeIdParam);
      request.toNodeId = std::stoi(toNodeIdParam);

      if (request.fromNodeId <= 0 || request.toNodeId <= 0)
      {
        return {false, "Node IDs must be positive numbers"};
      }

      return {true, ""};
    }
    catch (const std::exception &)
    {
      return {false, "Invalid node ID parameters. Must be numbers"};
    }
  }
};
