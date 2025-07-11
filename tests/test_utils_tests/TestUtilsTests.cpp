/**
 * @file TestUtilsTests.cpp
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

#include "TestUtils.hpp"

using namespace ::testing;
using namespace TestUtils;

namespace fs = std::filesystem;

class TestUtilsFixture : public Test {
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
  fs::path CURRENT_PATH{TESTS_PATH + "/test_utils_tests"};
};

TEST_F(TestUtilsFixture, DISABLED_WhoRunsMyTest) {
  // std::cout << "cwd: " << fs::current_path() << "\n";
  // std::cout << "argv[0]: " << argv[0] << "\n";
}

TEST_F(TestUtilsFixture, CheckCurrentDirectory) {
  // Check if the current directory is the expected one
  std::string current_path = fs::current_path().string();
  EXPECT_EQ(current_path, CURRENT_PATH);
}

TEST_F(TestUtilsFixture, CheckTempDirectory) {
  // Change to a temporary directory
  fs::path temp_dir = fs::temp_directory_path();
  fs::current_path(temp_dir);
  std::string current_path = fs::current_path().string();
  EXPECT_EQ(current_path, temp_dir.string());
}

TEST_F(TestUtilsFixture,
       CheckIfStdSystemWorkingDirectoryFollowsStdFilesystemCurrentPath) {
  // Check if the current directory is the expected one
  std::string current_path = fs::current_path().string();
  ASSERT_EQ(current_path, CURRENT_PATH);

  // Use std::system to check the working directory
  std::system("pwd > current_path.txt");
  std::ifstream file("current_path.txt");
  if (file.is_open()) {
    std::getline(file, current_path);
    file.close();
  }
  std::system("rm current_path.txt");
  ASSERT_EQ(current_path, CURRENT_PATH);

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
