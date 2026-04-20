#pragma once

#include <string>
#include <stdexcept>

enum class EdgeStatus
{
  Open = 1,
  Closed = 2,
};

// Convert EdgeStatus to string
inline std::string toString(EdgeStatus status) {
  switch (status) {
    case EdgeStatus::Open: return "Open";
    case EdgeStatus::Closed: return "Closed";
    default: throw std::invalid_argument("Invalid EdgeStatus");
  }
}

// Convert string to EdgeStatus
inline EdgeStatus edgeStatusFromString(const std::string& str) {
  if (str == "Open") return EdgeStatus::Open;
  if (str == "Closed") return EdgeStatus::Closed;
  throw std::invalid_argument("Invalid EdgeStatus string: " + str);
}

// Convert EdgeStatus to int
inline int toInt(EdgeStatus status) {
  return static_cast<int>(status);
}
