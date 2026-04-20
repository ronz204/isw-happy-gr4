#pragma once

#include <string>
#include <stdexcept>

enum class EdgeStatus
{
  Open = 1,
  Closed = 2,
  Blocked = 3,
  Maintenance = 4,
  WeatherClosed = 5,
  EventClosed = 6,
};

// Convert EdgeStatus to string
inline std::string toString(EdgeStatus status) {
  switch (status) {
    case EdgeStatus::Open: return "Open";
    case EdgeStatus::Closed: return "Closed";
    case EdgeStatus::Blocked: return "Blocked";
    case EdgeStatus::Maintenance: return "Maintenance";
    case EdgeStatus::WeatherClosed: return "WeatherClosed";
    case EdgeStatus::EventClosed: return "EventClosed";
    default: throw std::invalid_argument("Invalid EdgeStatus");
  }
}

// Convert string to EdgeStatus
inline EdgeStatus edgeStatusFromString(const std::string& str) {
  if (str == "Open") return EdgeStatus::Open;
  if (str == "Closed") return EdgeStatus::Closed;
  if (str == "Blocked") return EdgeStatus::Blocked;
  if (str == "Maintenance") return EdgeStatus::Maintenance;
  if (str == "WeatherClosed") return EdgeStatus::WeatherClosed;
  if (str == "EventClosed") return EdgeStatus::EventClosed;
  throw std::invalid_argument("Invalid EdgeStatus string: " + str);
}

// Convert EdgeStatus to int
inline int toInt(EdgeStatus status) {
  return static_cast<int>(status);
}
