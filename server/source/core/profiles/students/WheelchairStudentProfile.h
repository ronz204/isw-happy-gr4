#pragma once

#include "../Profile.h"
#include <cmath>
#include <limits>

class WheelchairStudentProfile : public Profile
{
public:
  // Apply wheelchair-specific weight modifiers
  double calculateEffectiveWeight(const Edge &edge) const override
  {
    double weight = edge.weight;
    PathType pathType = static_cast<PathType>(edge.pathType);

    // Stairs are inaccessible (return infinity for pathfinding)
    if (pathType == PathType::Stairs)
    {
      return std::numeric_limits<double>::infinity();
    }

    // Bonus for accessible paths
    if (pathType == PathType::Ramp || pathType == PathType::Elevator)
    {
      weight *= 0.9;
    }

    // Penalize steep slopes
    if (std::abs(edge.slope) > 5.0)
    {
      weight *= (1.0 + std::abs(edge.slope) / 10.0);
    }

    return weight;
  }

  // Check if edge is accessible for wheelchair
  bool isEdgeAccessible(const Edge &edge) const override
  {
    // First check: edge must be open
    if (!isEdgeOpen(edge))
    {
      return false;
    }

    // Wheelchair cannot use stairs
    PathType pathType = static_cast<PathType>(edge.pathType);
    if (pathType == PathType::Stairs)
    {
      return false;
    }

    return true;
  }

  // Wheelchair profile has no preferred nodes
  bool isPreferredNode(const Node &node) const override
  {
    return false;
  }

  // Wheelchair profile has no landmark bonus
  double getLandmarkBonus(const Node &node) const override
  {
    return 0.0;
  }

  ProfileType getProfileType() const override
  {
    return ProfileType::Wheelchair;
  }
};