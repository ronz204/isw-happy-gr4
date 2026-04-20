#pragma once

#include "../../database/enums/ProfileType.h"
#include "../../database/enums/EdgeType.h"
#include "../../database/enums/EdgeStatus.h"
#include "../../database/models/Edge.h"
#include "../../database/models/Node.h"

class Profile
{
public:
  virtual ~Profile() = default;

  // Calculate effective weight based on profile
  virtual double calculateEffectiveWeight(const Edge &edge) const = 0;

  // Check if edge is accessible for this profile
  virtual bool isEdgeAccessible(const Edge &edge) const = 0;

  // Check if node is preferred (for landmarks in NewStudent)
  virtual bool isPreferredNode(const Node &node) const = 0;

  // Get landmark bonus (used by NewStudent)
  virtual double getLandmarkBonus(const Node &node) const = 0;

  // Get the profile type
  virtual ProfileType getProfileType() const = 0;

protected:
  // Check if edge is open (not blocked, closed, etc.)
  bool isEdgeOpen(const Edge &edge) const
  {
    EdgeStatus status = static_cast<EdgeStatus>(edge.status);
    return status == EdgeStatus::Open;
  }
};
