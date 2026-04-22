#pragma once

#include <crow.h>
#include <string>

struct GetNodesByFloorRequest
{
  int floor;
};

class GetNodesByFloorSchema
{
public:
  // Validate floor parameter
  static std::pair<bool, std::string> validate(const std::string &floorStr, GetNodesByFloorRequest &request)
  {
    try
    {
      request.floor = std::stoi(floorStr);
      return {true, ""};
    }
    catch (const std::exception &)
    {
      return {false, "Invalid floor parameter. Must be a number"};
    }
  }
};