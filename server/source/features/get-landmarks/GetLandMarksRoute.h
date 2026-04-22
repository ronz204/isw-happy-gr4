#pragma once

#include <crow.h>
#include <memory>
#include "GetLandMarksHandler.h"
#include "../../database/ORM.h"

class GetLandMarksRoute
{
public:
  template <typename Middleware>
  static void setupRoutes(crow::App<Middleware> &app, Storage &storage)
  {
    auto handler = std::make_shared<GetLandMarksHandler>(storage);

    CROW_ROUTE(app, "/api/graph/landmarks")
        .methods(crow::HTTPMethod::GET)([handler]()
                                        { return handler->getLandmarks(); });
  }
};
