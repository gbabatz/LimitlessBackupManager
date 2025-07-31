#include <iostream>

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

#include "crow.h"

int main() {
  // Initialize the logger
  std::shared_ptr<spdlog::logger> logger;
  try {
    logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
  } catch (const spdlog::spdlog_ex &ex) {
    std::cout << "Log init failed: " << ex.what() << std::endl;
  }
  if (!logger) {
    std::cerr << "Logger initialization failed." << std::endl;
    return 1;
  }
  spdlog::set_default_logger(
      logger); // this redirects all logs to the default logger
  // logger->info("Application started"); // alternative way to log messages
  // with log object logger->debug("Debugging information: main.cpp is
  // running");

  spdlog::set_level(
      spdlog::level::debug); // this makes the debug log messages visible
  spdlog::info("Application started");
  spdlog::debug("Debugging information: main.cpp is running");


  // Start the CROW server
  crow::SimpleApp app;

  spdlog::info("Initiating CROW_ROUTE");
  CROW_ROUTE(app, "/")([]() { return "Hello world"; });

  app.port(18080).multithreaded().run();

  return 0;
}