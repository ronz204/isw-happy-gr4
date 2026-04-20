#pragma once

#include "../Profile.h"

class RegularStudentProfile : public Profile
{
public:
  // Regular profile uses base weight without modifications
  double calculateEffectiveWeight(const Edge &edge) const override
  {
    return edge.weight;
  }

  // Check if edge is accessible
  bool isEdgeAccessible(const Edge &edge) const override
  {
    // Only check if edge is open
    return isEdgeOpen(edge);
  }

  // Regular profile has no preferred nodes
  bool isPreferredNode(const Node &node) const override
  {
    return false;
  }

  // Regular profile has no landmark bonus
  double getLandmarkBonus(const Node &node) const override
  {
    return 0.0;
  }

  ProfileType getProfileType() const override
  {
    return ProfileType::Regular;
  }
};