#pragma once

#include <crow.h>
#include <memory>
#include "PatchOpenEdgeHandler.h"
#include "../../database/ORM.h"

class PatchOpenEdgeRoute
{
public:
  template <typename Middleware>
  static void setupRoutes(crow::App<Middleware> &app, Storage &storage)
  {
    auto handler = std::make_shared<PatchOpenEdgeHandler>(storage);

    CROW_ROUTE(app, "/api/edge/<string>/open")
        .methods(crow::HTTPMethod::PATCH)([handler](const std::string &edgeId)
                                          { return handler->openEdge(edgeId); });
  }
};
