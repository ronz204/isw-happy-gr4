#pragma once

#include "../models/Edge.h"
#include "../../database/ORM.h"
#include <vector>

class EdgeDao
{
private:
  Storage &storage;

public:
  EdgeDao(Storage &storage) : storage(storage) {}

  std::vector<Edge> getAll()
  {
    return storage.get_all<Edge>();
  }

  void update(const Edge &edge)
  {
    storage.update(edge);
  }
};
