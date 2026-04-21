#pragma once

#include <string>
#include <stdexcept>

enum class NodeType
{
  Waypoint = 0,
  Room = 1,
  Office = 2,
  Stairs = 3,
  Elevator = 4,
  Bathroom = 5,
  Service = 6,
  Entrance = 7,
  Library = 8,
  Cafeteria = 9,
  Parking = 10,
  Auditorium = 11,
};

// Convert NodeType to string
inline std::string toString(NodeType type) {
  switch (type) {
    case NodeType::Waypoint: return "Waypoint";
    case NodeType::Room: return "Room";
    case NodeType::Office: return "Office";
    case NodeType::Stairs: return "Stairs";
    case NodeType::Elevator: return "Elevator";
    case NodeType::Bathroom: return "Bathroom";
    case NodeType::Service: return "Service";
    case NodeType::Entrance: return "Entrance";
    case NodeType::Library: return "Library";
    case NodeType::Cafeteria: return "Cafeteria";
    case NodeType::Parking: return "Parking";
    case NodeType::Auditorium: return "Auditorium";
    default: throw std::invalid_argument("Invalid NodeType");
  }
}

// Convert string to NodeType
inline NodeType nodeTypeFromString(const std::string& str) {
  if (str == "Waypoint") return NodeType::Waypoint;
  if (str == "Room") return NodeType::Room;
  if (str == "Office") return NodeType::Office;
  if (str == "Stairs") return NodeType::Stairs;
  if (str == "Elevator") return NodeType::Elevator;
  if (str == "Bathroom") return NodeType::Bathroom;
  if (str == "Service") return NodeType::Service;
  if (str == "Entrance") return NodeType::Entrance;
  if (str == "Library") return NodeType::Library;
  if (str == "Cafeteria") return NodeType::Cafeteria;
  if (str == "Parking") return NodeType::Parking;
  if (str == "Auditorium") return NodeType::Auditorium;
  throw std::invalid_argument("Invalid NodeType string: " + str);
}

// Convert NodeType to int
inline int toInt(NodeType type) {
  return static_cast<int>(type);
}
