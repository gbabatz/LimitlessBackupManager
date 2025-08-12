#include "CopyDirectoryContents.hpp"

#include <filesystem>
#include <map>

#include <spdlog/spdlog.h>

namespace fs = std::filesystem;

// clang-format off
std::map<CopyMethod, fs::copy_options> copyOptionsMap = {
    {CopyMethod::DEFAULT,           fs::copy_options::update_existing},
    {CopyMethod::RECURSIVE,         fs::copy_options::recursive | fs::copy_options::update_existing},
    {CopyMethod::DIRS_STRUCTURE,    fs::copy_options::recursive | fs::copy_options::directories_only}};
// clang-format on

bool CopyDirectoryContents(
    const std::string &src_dir, const std::string &dst_dir,
    const CopyMethod &copy_method = CopyMethod::DEFAULT) {
  try {
    fs::copy(src_dir, dst_dir, copyOptionsMap[copy_method]);
    return true;
  } catch (const fs::filesystem_error &e) {
    spdlog::error("Failed to copy directory contents from {} to {}: {}",
                  src_dir, dst_dir, e.what());
    return false;
  }
}