#pragma once

#include "../../database/models/Node.h"
#include "../../database/ORM.h"
#include <vector>

class NodeDao
{
private:
  Storage &storage;

public:
  NodeDao(Storage &storage) : storage(storage) {}

  std::vector<Node> getAll()
  {
    return storage.get_all<Node>();
  }

  std::vector<Node> getLandmarks()
  {
    return storage.get_all<Node>(sql::where(sql::c(&Node::isLandmark) == true));
  }

  std::vector<Node> getByFloor(int floor)
  {
    return storage.get_all<Node>(sql::where(sql::c(&Node::floor) == floor));
  }

  void update(const Node &node)
  {
    storage.update(node);
  }
};
