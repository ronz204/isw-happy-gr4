#pragma once

#include "../../database/models/Graph.h"
#include "../../database/models/Node.h"
#include "../../database/models/Edge.h"
#include "../profiles/Profile.h"
#include <vector>
#include <memory>
#include <string>

struct PathNode
{
  std::string code;
  float px;
  float py;
  int type;

  PathNode() : code(""), px(0.0f), py(0.0f), type(0) {}
  PathNode(const std::string &code, float px, float py, int type)
      : code(code), px(px), py(py), type(type) {}
};

struct SearchResponse
{
  bool success;                // True if path was found
  std::vector<PathNode> path;  // Nodes in path order (start -> end)
  double distance;             // Total distance
  double time;                 // Execution time in milliseconds
  std::string algorithm;       // Algorithm name (e.g., "DFS", "BFS")

  SearchResponse() : success(false), distance(0.0), time(0.0), algorithm("") {}

  // Helper: Convert node IDs to PathNodes using graph data
  static std::vector<PathNode> convertToPathNodes(const std::vector<int> &nodeIds, const Graph &graph)
  {
    std::vector<PathNode> pathNodes;
    pathNodes.reserve(nodeIds.size());

    for (int nodeId : nodeIds)
    {
      const Node *node = graph.getNode(nodeId);
      if (node)
      {
        pathNodes.emplace_back(node->code, node->px, node->py, node->type);
      }
    }

    return pathNodes;
  }
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
