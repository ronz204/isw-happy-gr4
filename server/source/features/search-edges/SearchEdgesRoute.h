#pragma once

#include <crow.h>
#include <memory>
#include "SearchEdgesHandler.h"
#include "../../database/ORM.h"

class SearchEdgesRoute
{
public:
  template <typename Middleware>
  static void setupRoutes(crow::App<Middleware> &app, Storage &storage)
  {
    auto handler = std::make_shared<SearchEdgesHandler>(storage);

    CROW_ROUTE(app, "/api/edge/search")
        .methods(crow::HTTPMethod::GET)([handler](const crow::request &req)
                                        { return handler->searchEdges(req); });
  }
};
