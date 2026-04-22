#pragma once

#include <crow.h>
#include <memory>
#include "GetNodesByFloorHandler.h"
#include "../../database/ORM.h"

class GetNodesByFloorRoute
{
public:
  template <typename Middleware>
  static void setupRoutes(crow::App<Middleware> &app, Storage &storage)
  {
    auto handler = std::make_shared<GetNodesByFloorHandler>(storage);

    CROW_ROUTE(app, "/api/graph/floor/<string>")
        .methods(crow::HTTPMethod::GET)([handler](const std::string &floor)
                                        { return handler->getByFloor(floor); });
  }
};