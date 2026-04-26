#pragma once

#include <string>
#include <stdexcept>

enum class EdgeType
{
  Walking = 0,
  Vertical = 1,
};

// Convert EdgeType to string
inline std::string toString(EdgeType type)
{
  switch (type)
  {
  case EdgeType::Walking: return "Walking";
  case EdgeType::Vertical: return "Vertical";
  default:
    throw std::invalid_argument("Invalid EdgeType");
  }
}

// Convert string to EdgeType
inline EdgeType edgeTypeFromString(const std::string &str)
{
  if (str == "Walking") return EdgeType::Walking;
  if (str == "Vertical") return EdgeType::Vertical;
  throw std::invalid_argument("Invalid EdgeType string: " + str);
}

// Convert EdgeType to int
inline int toInt(EdgeType type)
{
  return static_cast<int>(type);
}
