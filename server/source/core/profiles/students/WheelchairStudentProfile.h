#pragma once

#include "../Profile.h"

class WheelchairStudentProfile : public Profile
{
public:
  double getWeight(const Edge &edge) const override
  {
    EdgeType type = static_cast<EdgeType>(edge.type);

    // Cannot use vertical edges
    if (type == EdgeType::Vertical)
      return std::numeric_limits<double>::infinity();

    return edge.weight;
  }

  double getNodeBonus(const Node &node) const override
  {
    return 0.0;
  }

  ProfileType getProfileType() const override
  {
    return ProfileType::Wheelchair;
  }

protected:
  bool canUseByProfile(const Edge &edge) const override
  {
    EdgeType type = static_cast<EdgeType>(edge.type);
    return type != EdgeType::Vertical;
  }
};