#pragma once

#include <crow.h>
#include <memory>
#include "PatchCloseEdgeHandler.h"
#include "../../database/ORM.h"

class PatchCloseEdgeRoute
{
public:
  template <typename Middleware>
  static void setupRoutes(crow::App<Middleware> &app, Storage &storage)
  {
    auto handler = std::make_shared<PatchCloseEdgeHandler>(storage);

    CROW_ROUTE(app, "/api/edge/<string>/close")
        .methods(crow::HTTPMethod::PATCH)([handler](const std::string &edgeId)
                                          { return handler->closeEdge(edgeId); });
  }
};