#pragma once

#include <crow.h>
#include "../../core/dal/NodeDao.h"
#include "../../database/ORM.h"
#include "GetLandMarksMapper.h"

class GetLandMarksHandler
{
private:
  Storage &storage;

public:
  GetLandMarksHandler(Storage &storage) : storage(storage) {}

  crow::json::wvalue getLandmarks()
  {
    NodeDao nodeDao(storage);
    auto landmarks = nodeDao.getLandmarks();

    return GetLandMarksMapper::toResponse(landmarks);
  }
};
