/**
 * @file StdToolsTests.cpp
 * @brief Unit tests for standard tools and filesystem operations that help to
 * understand the tooling used in this project.
 * @author      LimitlessBackupManager Contributors
 * @date        2025
 * @copyright   MIT License
 */

#include "gtest/gtest.h"

#include <filesystem>
#include <fstream>
#include <string>

using namespace ::testing;
namespace fs = std::filesystem;

#ifndef PROJECT_ROOT
#error "PROJECT_ROOT must be defined by the build system."
#define PROJECT_ROOT "" // dummy definition to avoid static analysis errors
#endif

const std::string PROJECT_ROOT_PATH = fs::canonical(PROJECT_ROOT);

const std::string TESTS_PATH = PROJECT_ROOT_PATH + "/tests";
const std::string LOGS_PATH = PROJECT_ROOT_PATH + "/logs";
const std::string SANDBOX_PATH = TESTS_PATH + "/_sandbox";
const std::string SRC_PATH = SANDBOX_PATH + "/source";
const std::string DEST_PATH = SANDBOX_PATH + "/destination";

int CreateSandboxDirectories(const fs::path &sandbox_path) {

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

void FinalizeDirectories(const fs::path &sandbox_path) {

  fs::current_path(sandbox_path.parent_path());

  auto command = "tree . -o " + LOGS_PATH + "/tree_output.txt";
  std::system(command.c_str());

  fs::remove_all(sandbox_path);
}

class StdToolsFixture : public Test {
public:
  void SetUp() override {
    // Initialize resources or state needed for tests
    CreateSandboxDirectories(sandbox_path);
  }

  void TearDown() override {
    // Clean up resources or state after tests
    FinalizeDirectories(sandbox_path);
  }

protected:
  fs::path sandbox_path{SANDBOX_PATH};
};

TEST_F(StdToolsFixture, DISABLED_WhoRunsMyTest) {
  // std::cout << "cwd: " << fs::current_path() << "\n";
  // std::cout << "argv[0]: " << argv[0] << "\n";
}

TEST_F(StdToolsFixture, CheckCurrentDirectory) {
  // Check if the current directory is the expected one
  std::string current_path = fs::current_path().string();
  EXPECT_EQ(current_path, TESTS_PATH);
}

TEST_F(StdToolsFixture, CheckTempDirectory) {
  // Change to a temporary directory
  fs::path temp_dir = fs::temp_directory_path();
  fs::current_path(temp_dir);
  std::string current_path = fs::current_path().string();
  EXPECT_EQ(current_path, temp_dir.string());
}

TEST_F(StdToolsFixture,
       CheckIfStdSystemWorkingDirectoryFollowsStdFilesystemCurrentPath) {
  // Check if the current directory is the expected one
  std::string current_path = fs::current_path().string();
  ASSERT_EQ(current_path, TESTS_PATH);

  // Use std::system to check the working directory
  std::system("pwd > current_path.txt");
  std::ifstream file("current_path.txt");
  if (file.is_open()) {
    std::getline(file, current_path);
    file.close();
  }
  std::system("rm current_path.txt");
  ASSERT_EQ(current_path, TESTS_PATH);

  // Change to a temporary directory
  fs::path temp_dir = fs::temp_directory_path();
  fs::current_path(temp_dir);

  current_path = fs::current_path().string();
  EXPECT_EQ(current_path, temp_dir.string());

  // Use std::system to check if the working directory follows the change
  std::system("pwd > current_path.txt");
  file.open("current_path.txt");
  if (file.is_open()) {
    std::getline(file, current_path);
    file.close();
  }
  std::system("rm current_path.txt");
  EXPECT_EQ(current_path, temp_dir.string());
}
