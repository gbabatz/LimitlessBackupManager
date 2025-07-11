/**
 * @file TestUtils.cpp
 * @brief
 * @author      LimitlessBackupManager Contributors
 * @date        2025
 * @copyright   MIT License
 */

#include "TestUtils.hpp"

#include <filesystem>
#include <iostream>
#include <string>

namespace TU = TestUtils;
namespace fs = std::filesystem;

const std::string TU::PROJECT_ROOT_PATH = fs::canonical(PROJECT_ROOT);

const std::string TU::TESTS_PATH = PROJECT_ROOT_PATH + "/tests";
const std::string TU::LOGS_PATH = PROJECT_ROOT_PATH + "/logs";
const std::string TU::SANDBOX_PATH = TESTS_PATH + "/_sandbox";
const std::string TU::SRC_PATH = SANDBOX_PATH + "/source";
const std::string TU::DEST_PATH = SANDBOX_PATH + "/destination";

int TU::CreateSandboxDirectories(const fs::path &sandbox_path) {

  std::error_code ec;
  (void)fs::remove_all(sandbox_path, ec);
  if (ec) {
    std::cerr << "Error removing existing sandbox directory: " << ec.message()
              << std::endl;
    return -1; // Return error code if removal fails
  }

  if (!fs::create_directories(sandbox_path, ec)) {
    std::cerr << "Error creating sandbox directory: " << ec.message()
              << std::endl;
    return -1; // Return error code if creation fails
  }

  auto src_path = sandbox_path / "source";
  auto dest_path = sandbox_path / "destination";

  if (!fs::create_directories(src_path, ec)) {
    std::cerr << "Error creating source directory: " << ec.message()
              << std::endl;
    return -1;
  }

  if (!fs::create_directories(dest_path, ec)) {
    std::cerr << "Error creating destination directory: " << ec.message()
              << std::endl;
    return -1;
  }

  return 0;
}

void TU::FinalizeDirectories(const fs::path &sandbox_path) {

  fs::current_path(sandbox_path.parent_path());

  auto command = "tree . -o " + LOGS_PATH + "/tree_output.txt";
  std::system(command.c_str());

  fs::remove_all(sandbox_path);
}
