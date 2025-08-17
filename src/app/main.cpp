#include "crow-server-settings.hpp"
#include "spdlog-settings.hpp"

#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

int main() {
  // initialize the logger
  InitializeLogger();

  // start the CROW server
  StartCrowServer();

  return 0;
}