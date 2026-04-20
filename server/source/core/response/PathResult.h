#pragma once

#include <vector>
#include <string>

struct PathResult
{
  std::vector<int> path;
  std::vector<double> segmentDistances;
  double totalDistance;
  long long executionTimeMicros;
  bool pathExists;
  std::string algorithm;
};
