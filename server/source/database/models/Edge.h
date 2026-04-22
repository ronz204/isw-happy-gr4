#pragma once

#include <string>

struct Edge
{
  int id;
  int type;
  int floor;
  int status;
  double weight;

  int fromNodeId;
  int toNodeId;
};
