#pragma once

#include "../../database/models/Graph.h"
#include "../profiles/ProfileContext.h"
#include "../response/TraversalResult.h"
#include "../response/PathResult.h"
#include <vector>
#include <string>

// Base interface for search strategies
class SearchStrategy
{
public:
  virtual ~SearchStrategy() = default;

  // Perform complete traversal from a starting node
  virtual TraversalResult traverse(
      const Graph &graph,
      int startNodeId,
      const ProfileContext &context) const = 0;

  // Find path between two nodes
  virtual PathResult findPath(
      const Graph &graph,
      int startNodeId,
      int endNodeId,
      const ProfileContext &context) const = 0;

  // Get strategy name
  virtual std::string getName() const = 0;
};
