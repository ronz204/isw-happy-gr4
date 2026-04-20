#pragma once

#include <string>

struct Edge
{
  int id;
  int status;
  int pathType;

  double weight;
  double slope;

  int fromNodeId;
  int toNodeId;
};
