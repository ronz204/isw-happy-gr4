#pragma once

#include "../../database/enums/ProfileType.h"
#include "../../database/enums/EdgeType.h"
#include "../../database/enums/EdgeStatus.h"
#include "../../database/models/Edge.h"
#include "../../database/models/Node.h"
#include <limits>

class Profile
{
public:
  virtual ~Profile() = default;

  // Get edge weight for this profile (infinity if not usable)
  virtual double getWeight(const Edge &edge) const = 0;

  // Get node bonus (negative = preferred, used in pathfinding)
  virtual double getNodeBonus(const Node &node) const = 0;

  // Get the profile type
  virtual ProfileType getProfileType() const = 0;

  // Check if edge can be used by this profile
  bool canUse(const Edge &edge) const
  {
    // Universal rule: closed edges cannot be used by anyone
    EdgeStatus status = static_cast<EdgeStatus>(edge.status);
    if (status != EdgeStatus::Open)
      return false;

    // Profile-specific rules
    return canUseByProfile(edge);
  }

protected:
  // Profile-specific edge validation (override if needed)
  virtual bool canUseByProfile(const Edge &edge) const { return true; }
};
