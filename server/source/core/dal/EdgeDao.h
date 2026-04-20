#pragma once

#include "../../database/models/Edge.h"
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

  Edge getById(int id)
  {
    return storage.get<Edge>(id);
  }

  void update(const Edge &edge)
  {
    storage.update(edge);
  }
};
