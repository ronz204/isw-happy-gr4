#pragma once

#include <string>
#include <stdexcept>

enum class NodeType
{
  Room = 1,
  Stairs = 2,
  Elevator = 3,
  Bathroom = 4,
};

// Convert NodeType to string
inline std::string toString(NodeType type) {
  switch (type) {
    case NodeType::Room: return "Room";
    case NodeType::Stairs: return "Stairs";
    case NodeType::Elevator: return "Elevator";
    case NodeType::Bathroom: return "Bathroom";
    default: throw std::invalid_argument("Invalid NodeType");
  }
}

// Convert string to NodeType
inline NodeType nodeTypeFromString(const std::string& str) {
  if (str == "Room") return NodeType::Room;
  if (str == "Stairs") return NodeType::Stairs;
  if (str == "Elevator") return NodeType::Elevator;
  if (str == "Bathroom") return NodeType::Bathroom;
  throw std::invalid_argument("Invalid NodeType string: " + str);
}

// Convert NodeType to int
inline int toInt(NodeType type) {
  return static_cast<int>(type);
}
