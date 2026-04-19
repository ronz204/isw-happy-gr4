#pragma once

#include <string>

struct Edge
{
  int id;
  int status;
  double weight;

  int fromNodeId;
  int toNodeId;
};
