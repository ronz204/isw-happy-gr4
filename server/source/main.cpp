#include <crow.h>
#include "database/ORM.h"
#include <crow/middlewares/cors.h>
#include "features/visualize-graph/VisualizeGraphRoute.h"
#include "features/navigate-graph/NavigateGraphRoute.h"
#include "features/update-edge/UpdateEdgeRoute.h"

int main()
{
  auto storage = initStorage("happy.db");
  storage.sync_schema();

  crow::App<crow::CORSHandler> app;

  // Configure CORS middleware
  auto &cors = app.get_middleware<crow::CORSHandler>();
  cors.global().headers("Content-Type")
      .methods("GET"_method, "POST"_method, "PUT"_method, "DELETE"_method, "PATCH"_method)
      .origin("*");

  // Health check endpoint
  CROW_ROUTE(app, "/health")
  ([]() {
    crow::json::wvalue response;
    response["status"] = "Healthy";
    response["service"] = "Happy GR4";
    return response;
  });

  // Register feature routes
  VisualizeGraphRoute::setupRoutes(app, storage);
  NavigateGraphRoute::setupRoutes(app, storage);
  UpdateEdgeRoute::setupRoutes(app, storage);

  app.port(4000).multithreaded().run();
}
