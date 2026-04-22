#pragma once

#include <crow.h>
#include <string>

struct PatchCloseEdgeRequest
{
  int edgeId;
};

class PatchCloseEdgeSchema
{
public:
  // Validate edge ID parameter
  static std::pair<bool, std::string> validate(const std::string &edgeIdStr, PatchCloseEdgeRequest &request)
  {
    try
    {
      request.edgeId = std::stoi(edgeIdStr);
      if (request.edgeId <= 0)
      {
        return {false, "Edge ID must be a positive number"};
      }
      return {true, ""};
    }
    catch (const std::exception &)
    {
      return {false, "Invalid edge ID parameter. Must be a number"};
    }
  }
};