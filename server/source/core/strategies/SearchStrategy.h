#pragma once

#include "../../database/models/Graph.h"
#include "../../database/models/Node.h"
#include "../../database/models/Edge.h"
#include "../profiles/Profile.h"
#include <vector>
#include <memory>
#include <string>

struct SearchResponse
{
  bool success;           // True if path was found
  std::vector<int> path;  // Node IDs in path order (start -> end)
  double distance;        // Total distance
  double time;            // Execution time in milliseconds
  std::string algorithm;  // Algorithm name (e.g., "DFS", "BFS")

  SearchResponse() : success(false), distance(0.0), time(0.0), algorithm("") {}
};

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
