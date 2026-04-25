#pragma once

#include <crow.h>
#include <memory>
#include "GetPerformanceHandler.h"
#include "../../database/ORM.h"

class GetPerformanceRoute
{
public:
  template <typename Middleware>
  static void setupRoutes(crow::App<Middleware> &app, Storage &storage)
  {
    auto handler = std::make_shared<GetPerformanceHandler>(storage);

    CROW_ROUTE(app, "/api/graph/performance")
        .methods(crow::HTTPMethod::POST)([handler](const crow::request &req)
                                         { return handler->handle(req); });
  }
};
