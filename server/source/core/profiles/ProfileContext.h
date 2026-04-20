#pragma once

#include "../../database/enums/UserProfile.h"
#include "../../database/enums/PathType.h"
#include "../../database/models/Edge.h"
#include "../../database/models/Node.h"
#include <cmath>
#include <limits>

class ProfileContext
{
private:
  UserProfile profile;

public:
  ProfileContext(UserProfile profile) : profile(profile) {}

  // Calculate effective weight based on user profile
  double calculateEffectiveWeight(const Edge &edge) const
  {
    double weight = edge.weight;
    PathType pathType = static_cast<PathType>(edge.pathType);

    switch (profile)
    {
    case UserProfile::Wheelchair:
      // Wheelchair cannot use stairs
      if (pathType == PathType::Stairs)
      {
        return std::numeric_limits<double>::infinity();
      }
      // Penalize steep slopes
      if (std::abs(edge.slope) > 5.0)
      {
        weight *= (1.0 + std::abs(edge.slope) / 10.0);
      }
      // Bonus for ramps and elevators
      if (pathType == PathType::Ramp || pathType == PathType::Elevator)
      {
        weight *= 0.9;
      }
      break;

    case UserProfile::Crutches:
      // Crutches have difficulty with stairs
      if (pathType == PathType::Stairs)
      {
        weight *= 3.0;
      }
      // Penalize slopes
      if (std::abs(edge.slope) > 3.0)
      {
        weight *= (1.0 + std::abs(edge.slope) / 15.0);
      }
      break;

    case UserProfile::LimitedMobility:
      // Limited mobility avoids stairs and slopes
      if (pathType == PathType::Stairs)
      {
        weight *= 2.0;
      }
      if (std::abs(edge.slope) > 4.0)
      {
        weight *= (1.0 + std::abs(edge.slope) / 20.0);
      }
      break;

    case UserProfile::NewStudent:
    case UserProfile::Regular:
    case UserProfile::Staff:
    case UserProfile::Visitor:
    default:
      // Use base weight without modifications
      break;
    }

    return weight;
  }

  // Check if edge is accessible for this profile
  bool isEdgeAccessible(const Edge &edge) const
  {
    PathType pathType = static_cast<PathType>(edge.pathType);

    // Wheelchair cannot use stairs
    if (profile == UserProfile::Wheelchair && pathType == PathType::Stairs)
    {
      return false;
    }

    return true;
  }

  // Check if node is preferred (for landmarks in NewStudent)
  bool isPreferredNode(const Node &node) const
  {
    if (profile == UserProfile::NewStudent)
    {
      return node.isLandmark;
    }
    return false;
  }

  // Get landmark bonus (used by NewStudent)
  double getLandmarkBonus(const Node &node) const
  {
    if (profile == UserProfile::NewStudent && node.isLandmark)
    {
      // Bonus based on level: lower level = higher bonus
      // landmarkLvl: 1=very important, 5=less important
      return -5.0 * (6 - node.landmarkLvl);
    }
    return 0.0;
  }

  UserProfile getProfile() const { return profile; }
};
