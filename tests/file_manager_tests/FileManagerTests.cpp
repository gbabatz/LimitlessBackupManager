/**
 * @file FileCopyTests.cpp
 * @brief Unit tests for FileCopy module.
 * @author      LimitlessBackupManager Contributors
 * @date        2025
 * @copyright   MIT License
 */

#include "gtest/gtest.h"
// #include "gmock/gmock.h"

#include "FileManager.hpp"
#include "TestUtils.hpp"

#include <filesystem>
#include <fstream>
#include <memory>
#include <string>

#include "CopyDirectoryContents.hpp"

namespace fs = std::filesystem;

using namespace ::testing;

class FileManagerFixture : public Test {
protected:
  std::unique_ptr<FileManager> fileManager_ptr;

  void SetUp() override {
    // Setup code if needed
    fileManager_ptr = std::make_unique<FileManager>();
    TestUtils::CreateSandboxDirectories(TestUtils::SANDBOX_PATH);
    fs::current_path(TestUtils::SANDBOX_PATH);
  }

  void TearDown() override {
    // Cleanup code if needed
    fileManager_ptr.reset();
    TestUtils::FinalizeDirectories(TestUtils::SANDBOX_PATH);
  }
};

TEST_F(FileManagerFixture, CreateManager) {
  // Check if the FileManager instance is created successfully
  EXPECT_TRUE(fileManager_ptr != nullptr);
  EXPECT_TRUE(dynamic_cast<FileManager *>(fileManager_ptr.get()) != nullptr);
}

TEST_F(FileManagerFixture, CopyFile_Success) {

  std::string test_file = "test_file.txt";
  std::string test_file_source = TestUtils::SRC_PATH + "/" + test_file;
  std::string test_file_dest = TestUtils::DST_PATH + "/" + test_file;

  std::string test_file_sample_txt = "This is a test file.";

  std::ofstream(test_file_source) << test_file_sample_txt;

  // Perform the copy operation
  bool result =
      fileManager_ptr->CopyFile(test_file_source, TestUtils::DST_PATH);

  // Check if the copy was successful
  EXPECT_TRUE(result);

  // Verify the test_file_dest file exists and has the correct content
  std::ifstream destFile(test_file_dest);
  std::string content((std::istreambuf_iterator<char>(destFile)),
                      std::istreambuf_iterator<char>());

  EXPECT_EQ(content, test_file_sample_txt);
}

TEST_F(FileManagerFixture, CopyFile_Failure) {
  std::string non_existent_file = "non_existent_file.txt";
  std::string test_file_dest = TestUtils::DST_PATH + "/" + non_existent_file;

  // Attempt to copy a non-existent file
  bool result =
      fileManager_ptr->CopyFile(non_existent_file, TestUtils::DST_PATH);

  // Check if the copy operation failed
  EXPECT_FALSE(result);

  // Verify that the destination file does not exist
  EXPECT_FALSE(fs::exists(test_file_dest));
}

// TODO: Needs further testing
// TODO: Add helper function to make evaluation of copied files easier
//       Check if file exists, has correct content, etc.
TEST_F(FileManagerFixture, CopyDirectoryContents_DefaultOption_Success) {
  fs::create_directories(TestUtils::SRC_PATH + "subdir");

  std::ofstream(TestUtils::SRC_PATH + "/file1.txt").put('a');
  std::ofstream(TestUtils::SRC_PATH + "/file2.txt").put('a');
  std::ofstream(TestUtils::SRC_PATH + "/subdir/file3.txt").put('a');

  std::ofstream(TestUtils::DST_PATH + "/file1.txt").put('a');

  CopyDirectoryContents(TestUtils::SRC_PATH, TestUtils::DST_PATH,
                        CopyMethod::DEFAULT);

  EXPECT_TRUE(fs::exists(TestUtils::DST_PATH + "/file1.txt"));
}