#!/usr/bin/bash

echo "Building TEST mode..."

# Get the absolute path to the project root (directory of this script)
export PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)" 

mkdir -p ./build/tests

cmake -S . -B ./build/tests \
    -DBUILD_MODE=TEST \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    -DPROJECT_ROOT="${PROJECT_ROOT}"
cmake --build ./build/tests -j$(nproc)
echo "Test build complete."