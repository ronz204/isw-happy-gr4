#pragma once

#include <string>
#include <stdexcept>

enum class PathType
{
  Hallway = 1,
  Stairs = 2,
  Ramp = 3,
  Elevator = 4,
  Outdoor = 5,
  Bridge = 6,
};

// Convert PathType to string
inline std::string toString(PathType type)
{
  switch (type)
  {
  case PathType::Hallway:
    return "Hallway";
  case PathType::Stairs:
    return "Stairs";
  case PathType::Ramp:
    return "Ramp";
  case PathType::Elevator:
    return "Elevator";
  case PathType::Outdoor:
    return "Outdoor";
  case PathType::Bridge:
    return "Bridge";
  default:
    throw std::invalid_argument("Invalid PathType");
  }
}

// Convert string to PathType
inline PathType pathTypeFromString(const std::string &str)
{
  if (str == "Hallway")
    return PathType::Hallway;
  if (str == "Stairs")
    return PathType::Stairs;
  if (str == "Ramp")
    return PathType::Ramp;
  if (str == "Elevator")
    return PathType::Elevator;
  if (str == "Outdoor")
    return PathType::Outdoor;
  if (str == "Bridge")
    return PathType::Bridge;
  throw std::invalid_argument("Invalid PathType string: " + str);
}

// Convert PathType to int
inline int toInt(PathType type)
{
  return static_cast<int>(type);
}
