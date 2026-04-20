#pragma once

#include <crow.h>
#include <memory>
#include "UpdateEdgeHandler.h"
#include "../../database/ORM.h"

class UpdateEdgeRoute
{
public:
  template <typename Middleware>
  static void setupRoutes(crow::App<Middleware> &app, Storage &storage)
  {
    auto handler = std::make_shared<UpdateEdgeHandler>(storage);

    CROW_ROUTE(app, "/api/edges/<int>")
        .methods(crow::HTTPMethod::PATCH)([handler](const crow::request &req, int edgeId)
                                          { return handler->updateEdge(edgeId, req); });
  }
};
