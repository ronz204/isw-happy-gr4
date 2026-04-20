#pragma once

#include "../../database/enums/UserProfile.h"
#include "../../database/enums/PathType.h"
#include "../../database/enums/EdgeStatus.h"
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
      weight = applyWheelchairModifiers(weight, pathType, edge.slope);
      break;

    case UserProfile::Crutches:
      weight = applyCrutchesModifiers(weight, pathType, edge.slope);
      break;

    case UserProfile::LimitedMobility:
      weight = applyLimitedMobilityModifiers(weight, pathType, edge.slope);
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
    // First check: edge must be open (status-based accessibility)
    if (!isEdgeOpen(edge))
    {
      return false;
    }

    // Second check: profile-specific restrictions
    return isEdgeAccessibleForProfile(edge);
  }

private:
  // Check if edge is open (not blocked, closed, etc.)
  bool isEdgeOpen(const Edge &edge) const
  {
    EdgeStatus status = static_cast<EdgeStatus>(edge.status);
    return status == EdgeStatus::Open;
  }

  // Check profile-specific accessibility restrictions
  bool isEdgeAccessibleForProfile(const Edge &edge) const
  {
    PathType pathType = static_cast<PathType>(edge.pathType);

    // Wheelchair cannot use stairs (already handled but kept for clarity)
    if (profile == UserProfile::Wheelchair && pathType == PathType::Stairs)
    {
      return false;
    }

    return true;
  }

  // Apply wheelchair-specific weight modifiers
  double applyWheelchairModifiers(double weight, PathType pathType, double slope) const
  {
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
    if (std::abs(slope) > 5.0)
    {
      weight *= (1.0 + std::abs(slope) / 10.0);
    }

    return weight;
  }

  // Apply crutches-specific weight modifiers
  double applyCrutchesModifiers(double weight, PathType pathType, double slope) const
  {
    // Stairs are difficult but possible
    if (pathType == PathType::Stairs)
    {
      weight *= 3.0;
    }

    // Penalize slopes
    if (std::abs(slope) > 3.0)
    {
      weight *= (1.0 + std::abs(slope) / 15.0);
    }

    return weight;
  }

  // Apply limited mobility weight modifiers
  double applyLimitedMobilityModifiers(double weight, PathType pathType, double slope) const
  {
    // Stairs are challenging
    if (pathType == PathType::Stairs)
    {
      weight *= 2.0;
    }

    // Penalize slopes
    if (std::abs(slope) > 4.0)
    {
      weight *= (1.0 + std::abs(slope) / 20.0);
    }

    return weight;
  }

public:

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
