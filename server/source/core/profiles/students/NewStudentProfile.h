#pragma once

#include "../Profile.h"

class NewStudentProfile : public Profile
{
public:
  double getWeight(const Edge &edge) const override
  {
    return edge.weight;
  }

  double getNodeBonus(const Node &node) const override
  {
    if (!node.isLandmark) return 0.0;

    // Negative bonus = preferred (lower cost in pathfinding)
    // landmarkLvl: 1=most important, higher=less important
    return -5.0 * (6 - node.landmarkLvl);
  }

  ProfileType getProfileType() const override
  {
    return ProfileType::NewStudent;
  }
};