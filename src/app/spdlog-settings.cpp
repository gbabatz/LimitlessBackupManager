#include "spdlog-settings.hpp"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

#include <iostream>
#include <memory>

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
  // spdlog::set_level(spdlog::level::debug);
  spdlog::info("Logger initialized successfully");
}