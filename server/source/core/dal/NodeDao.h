#pragma once

#include "../models/Node.h"
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

  void update(const Node &node)
  {
    storage.update(node);
  }
};
