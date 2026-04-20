#pragma once

#include "Profile.h"

class NewStudentProfile : public Profile
{
public:
  // NewStudent profile uses base weight without modifications
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

  // NewStudent prefers landmarks
  bool isPreferredNode(const Node &node) const override
  {
    return node.isLandmark;
  }

  // Get landmark bonus based on level
  double getLandmarkBonus(const Node &node) const override
  {
    if (node.isLandmark)
    {
      // Bonus based on level: lower level = higher bonus
      // landmarkLvl: 1=very important, 5=less important
      return -5.0 * (6 - node.landmarkLvl);
    }
    return 0.0;
  }

  ProfileType getProfileType() const override
  {
    return ProfileType::NewStudent;
  }
};
