#include "crow-server-settings.hpp"

#include "spdlog-settings.hpp"
#include "spdlog/spdlog.h"

int main() {
  spdlog::debug("main.cpp is running");

  // initialize the logger
  InitializeLogger();
  spdlog::info("Application started");

  // start the CROW server
  StartCrowServer();

  return 0;
}