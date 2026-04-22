#pragma once

#include <crow.h>
#include <memory>
#include "GetGraphFullHandler.h"
#include "../../database/ORM.h"

class GetGraphFullRoute
{
public:
  template <typename Middleware>
  static void setupRoutes(crow::App<Middleware> &app, Storage &storage)
  {
    auto handler = std::make_shared<GetGraphFullHandler>(storage);

    CROW_ROUTE(app, "/api/graph/full")
        .methods(crow::HTTPMethod::GET)([handler]()
                                        { return handler->getFullGraph(); });
  }
};