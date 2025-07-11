/**
 * @file TestUtils.hpp
 * @brief
 * @author      LimitlessBackupManager Contributors
 * @date        2025
 * @copyright   MIT License
 */

#ifndef TESTUTILS_HPP
#define TESTUTILS_HPP

#ifndef PROJECT_ROOT
#error "PROJECT_ROOT must be defined by the build system."
#define PROJECT_ROOT "" // dummy definition to avoid static analysis errors
#endif

#include <filesystem>
#include <string>

namespace TestUtils {

extern const std::string PROJECT_ROOT_PATH;
extern const std::string TESTS_PATH;
extern const std::string LOGS_PATH;
extern const std::string SANDBOX_PATH;
extern const std::string SRC_PATH;
extern const std::string DEST_PATH;

int CreateSandboxDirectories(const std::filesystem::path &sandbox_path);
void FinalizeDirectories(const std::filesystem::path &sandbox_path);

} // namespace TestUtils

#endif // TESTUTILS_HPP