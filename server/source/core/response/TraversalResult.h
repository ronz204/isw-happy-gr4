#pragma once

#include <vector>
#include <string>

struct TraversalResult
{
  std::vector<int> visitedNodes;
  std::vector<double> cumulativeDistances;
  long long executionTimeMicros;
  int nodesVisited;
  std::string algorithm;
};
