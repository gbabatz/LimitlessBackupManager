/**
 * @file FileManager.cpp
 * @brief
 * @author      LimitlessBackupManager Contributors
 * @date        2025
 * @copyright   MIT License
 */

#include "FileManager.hpp"

#include <filesystem>

namespace fs = std::filesystem;

bool FileManager::CopyFile(const std::string &source,
                           const std::string &destination) {
  try {
    fs::copy(source, destination, fs::copy_options::overwrite_existing);
    return true;
  } catch (const fs::filesystem_error &e) {
    // Handle error (e.g., log it)
    return false;
  }
}

bool FileManager::MoveFile(const std::string &source,
                           const std::string &destination) {
  return 0;
}
bool FileManager::DeleteFile(const std::string &path) { return 0; }
bool FileManager::CopyDirectory(const std::string &source,
                                const std::string &destination) {
  return 0;
}
std::vector<std::string>
FileManager::ListFilesInDirectory(const std::string &directory) const {
  return std::vector<std::string>();
}
bool FileManager::FileExists(const std::string &path) const { return 0; }