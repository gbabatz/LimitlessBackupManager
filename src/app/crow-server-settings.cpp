#include "crow-server-settings.hpp"
#include "crow.h"

#include "spdlog/spdlog.h"

#include <fstream>
#include <sstream>

std::string readFile(const std::string &path) {
  std::ifstream file(path);
  std::ostringstream ss;
  ss << file.rdbuf();
  return ss.str();
}

void StartCrowServer() {
  // start the CROW server
  crow::SimpleApp app;

  // CROW_ROUTE(app, "/")([]() { return "Hello world"; });

  // Serve static files from "./ui"
  CROW_ROUTE(app, "/")([] {
    crow::response res;
    res.code = 200;
    res.set_header("Content-Type", "text/html");
    res.body = readFile("ui/index.html");
    return res;
  });

  CROW_ROUTE(app, "/app.js")([] {
    crow::response res;
    res.code = 200;
    res.set_header("Content-Type", "application/javascript");
    res.body = readFile("ui/app.js");
    return res;
  });

  app.port(18080).multithreaded().run();
  spdlog::info("CROW server started on port 18080");
}