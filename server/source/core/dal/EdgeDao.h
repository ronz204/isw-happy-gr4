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

  std::vector<Edge> getByFloor(int floor)
  {
    return storage.get_all<Edge>(sql::where(sql::c(&Edge::floor) == floor));
  }

  std::vector<Edge> findByNodes(int fromNodeId, int toNodeId)
  {
    return storage.get_all<Edge>(
      sql::where(
        (sql::c(&Edge::fromNodeId) == fromNodeId and sql::c(&Edge::toNodeId) == toNodeId)
        or
        (sql::c(&Edge::fromNodeId) == toNodeId and sql::c(&Edge::toNodeId) == fromNodeId)
      )
    );
  }

  void update(const Edge &edge)
  {
    storage.update(edge);
  }
};
