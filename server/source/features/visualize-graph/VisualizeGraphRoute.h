#pragma once

#include <crow.h>
#include "VisualizeGraphHandler.h"
#include "../../database/ORM.h"
#include <memory>

class VisualizeGraphRoute
{
public:
  template <typename Middleware>
  static void setupRoutes(crow::App<Middleware> &app, Storage &storage)
  {
    auto handler = std::make_shared<VisualizeGraphHandler>(storage);

    CROW_ROUTE(app, "/api/graph")
        .methods(crow::HTTPMethod::GET)([handler]()
                                        { return handler->getGraph(); });
  }
};