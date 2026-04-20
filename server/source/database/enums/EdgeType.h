#pragma once

#include <string>
#include <stdexcept>

enum class EdgeType
{
  Hallway = 1,
  Stairs = 2,
  Ramp = 3,
  Elevator = 4,
  Outdoor = 5,
  Bridge = 6,
};

// Convert EdgeType to string
inline std::string toString(EdgeType type)
{
  switch (type)
  {
  case EdgeType::Hallway:
    return "Hallway";
  case EdgeType::Stairs:
    return "Stairs";
  case EdgeType::Ramp:
    return "Ramp";
  case EdgeType::Elevator:
    return "Elevator";
  case EdgeType::Outdoor:
    return "Outdoor";
  case EdgeType::Bridge:
    return "Bridge";
  default:
    throw std::invalid_argument("Invalid EdgeType");
  }
}

// Convert string to EdgeType
inline EdgeType edgeTypeFromString(const std::string &str)
{
  if (str == "Hallway")
    return EdgeType::Hallway;
  if (str == "Stairs")
    return EdgeType::Stairs;
  if (str == "Ramp")
    return EdgeType::Ramp;
  if (str == "Elevator")
    return EdgeType::Elevator;
  if (str == "Outdoor")
    return EdgeType::Outdoor;
  if (str == "Bridge")
    return EdgeType::Bridge;
  throw std::invalid_argument("Invalid EdgeType string: " + str);
}

// Convert EdgeType to int
inline int toInt(EdgeType type)
{
  return static_cast<int>(type);
}
