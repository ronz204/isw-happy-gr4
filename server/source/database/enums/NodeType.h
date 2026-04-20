#pragma once

#include <string>
#include <stdexcept>

enum class NodeType
{
  Room = 1,
  Stairs = 2,
  Elevator = 3,
  Bathroom = 4,
  Junction = 5,
  Entrance = 6,
  Library = 7,
  Cafeteria = 8,
  Parking = 9,
  Office = 10,
  Classroom = 11,
  Lab = 12,
  Auditorium = 13,
};

// Convert NodeType to string
inline std::string toString(NodeType type) {
  switch (type) {
    case NodeType::Room: return "Room";
    case NodeType::Stairs: return "Stairs";
    case NodeType::Elevator: return "Elevator";
    case NodeType::Bathroom: return "Bathroom";
    case NodeType::Junction: return "Junction";
    case NodeType::Entrance: return "Entrance";
    case NodeType::Library: return "Library";
    case NodeType::Cafeteria: return "Cafeteria";
    case NodeType::Parking: return "Parking";
    case NodeType::Office: return "Office";
    case NodeType::Classroom: return "Classroom";
    case NodeType::Lab: return "Lab";
    case NodeType::Auditorium: return "Auditorium";
    default: throw std::invalid_argument("Invalid NodeType");
  }
}

// Convert string to NodeType
inline NodeType nodeTypeFromString(const std::string& str) {
  if (str == "Room") return NodeType::Room;
  if (str == "Stairs") return NodeType::Stairs;
  if (str == "Elevator") return NodeType::Elevator;
  if (str == "Bathroom") return NodeType::Bathroom;
  if (str == "Junction") return NodeType::Junction;
  if (str == "Entrance") return NodeType::Entrance;
  if (str == "Library") return NodeType::Library;
  if (str == "Cafeteria") return NodeType::Cafeteria;
  if (str == "Parking") return NodeType::Parking;
  if (str == "Office") return NodeType::Office;
  if (str == "Classroom") return NodeType::Classroom;
  if (str == "Lab") return NodeType::Lab;
  if (str == "Auditorium") return NodeType::Auditorium;
  throw std::invalid_argument("Invalid NodeType string: " + str);
}

// Convert NodeType to int
inline int toInt(NodeType type) {
  return static_cast<int>(type);
}
