#pragma once

#include <string>

struct Node
{
  int id;
  int type;
  int floor;
  float px, py;

  std::string code;
  std::string label;

  bool isLandmark;
};
