#include <iostream>

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

#include "crow.h"

#include <fstream>
#include <sstream>

std::string readFile(const std::string &path) {
  std::ifstream file(path);
  std::ostringstream ss;
  ss << file.rdbuf();
  return ss.str();
}

std::shared_ptr<spdlog::logger> g_logger;

void InitializeLogger() {
  try {
    g_logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
  } catch (const spdlog::spdlog_ex &ex) {
    std::cout << "Log init failed: " << ex.what() << std::endl;
  }
  if (!g_logger) {
    std::cerr << "Logger initialization failed." << std::endl;
    std::exit(EXIT_FAILURE);
  }

  // redirect all logs to the default logger
  spdlog::set_default_logger(g_logger);

  // alternative way to log messages with log objects
  // logger->info("Application started");
  // logger->debug("Debugging information: main.cpp is running");

  // make the debug log messages visible
  spdlog::set_level(spdlog::level::debug);
}

void StartCrowAndServer() {
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

int main() {
  // initialize the logger
  InitializeLogger();

  spdlog::info("Application started");
  spdlog::debug("main.cpp is running");

  // start the CROW server
  StartCrowAndServer();

  return 0;
}