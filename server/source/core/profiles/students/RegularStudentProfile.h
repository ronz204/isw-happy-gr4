#pragma once

#include "../Profile.h"

class RegularStudentProfile : public Profile
{
public:
  double getWeight(const Edge &edge) const override
  {
    return edge.weight;
  }

  double getNodeBonus(const Node &node) const override
  {
    return 0.0;
  }

  ProfileType getProfileType() const override
  {
    return ProfileType::Regular;
  }
};