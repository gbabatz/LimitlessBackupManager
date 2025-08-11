#ifndef SPDLOG_SETTINGS_HPP
#define SPDLOG_SETTINGS_HPP

#include <memory>

// #include "spdlog/spdlog.h"
// Forward declaration of the logger to avoid unnecessary includes in headers
namespace spdlog {
class logger;
}

extern std::shared_ptr<spdlog::logger> g_logger;

void InitializeLogger();

#endif // SPDLOG_SETTINGS_HPP