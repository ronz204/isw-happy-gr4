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
    PathType edgeType = static_cast<PathType>(edge.type);

    // Stairs are inaccessible (return infinity for pathfinding)
    if (edgeType == PathType::Stairs)
    {
      return std::numeric_limits<double>::infinity();
    }

    // Bonus for accessible paths (elevator is easier)
    if (edgeType == PathType::Elevator)
    {
      weight *= 0.9;
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
    PathType edgeType = static_cast<PathType>(edge.type);
    if (edgeType == PathType::Stairs)
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