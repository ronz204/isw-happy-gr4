#pragma once

#include <crow.h>
#include <memory>
#include "NavigateGraphHandler.h"
#include "../../database/ORM.h"

class NavigateGraphRoute
{
public:
  template <typename Middleware>
  static void setupRoutes(crow::App<Middleware> &app, Storage &storage)
  {
    auto handler = std::make_shared<NavigateGraphHandler>(storage);

    CROW_ROUTE(app, "/api/graph/route")
        .methods(crow::HTTPMethod::POST)([handler](const crow::request &req)
                                         { return handler->navigate(req); });
  }
};
