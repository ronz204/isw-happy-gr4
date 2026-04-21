#pragma once

#include <string>
#include <stdexcept>

enum class NodeType
{
  Waypoint = 0,
  Room = 1,
  Office = 2,
  StairsUp = 3,
  StairsDown = 4,
  Elevator = 5,
  BathroomF = 6,
  BathroomM = 7,
  Service = 8,
  Entrance = 9,
  Library = 10,
  Cafeteria = 11,
  Parking = 12,
  Auditorium = 13,
};

// Convert NodeType to string
inline std::string toString(NodeType type) {
  switch (type) {
    case NodeType::Waypoint: return "Waypoint";
    case NodeType::Room: return "Room";
    case NodeType::Office: return "Office";
    case NodeType::StairsUp: return "StairsUp";
    case NodeType::StairsDown: return "StairsDown";
    case NodeType::Elevator: return "Elevator";
    case NodeType::BathroomM: return "BathroomM";
    case NodeType::BathroomF: return "BathroomF";
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
  if (str == "Elevator") return NodeType::Elevator;
  if (str == "BathroomM") return NodeType::BathroomM;
  if (str == "BathroomF") return NodeType::BathroomF;
  if (str == "Service") return NodeType::Service;
  if (str == "Entrance") return NodeType::Entrance;
  if (str == "Library") return NodeType::Library;
  if (str == "Cafeteria") return NodeType::Cafeteria;
  if (str == "Parking") return NodeType::Parking;
  if (str == "Auditorium") return NodeType::Auditorium;
  if (str == "StairsUp") return NodeType::StairsUp;
  if (str == "StairsDown") return NodeType::StairsDown;
  throw std::invalid_argument("Invalid NodeType string: " + str);
}

// Convert NodeType to int
inline int toInt(NodeType type) {
  return static_cast<int>(type);
}
