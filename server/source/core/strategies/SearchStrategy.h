#pragma once

#include "SearchResponse.h"
#include "../../database/models/Graph.h"
#include "../../database/models/Edge.h"
#include "../profiles/Profile.h"

class SearchStrategy
{
public:
  virtual ~SearchStrategy() = default;

  // Search for path from startNodeId to endNodeId
  // Graph: the graph to search in
  // Profile: defines edge weights and accessibility rules
  virtual SearchResponse search(
      const Graph &graph,
      const Profile &profile,
      int startNodeId,
      int endNodeId) const = 0;
};
