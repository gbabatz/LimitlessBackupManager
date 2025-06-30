#!/usr/bin/bash

# rm -rf ./build-debug
mkdir -p ./build-debug

echo "Building DEBUG mode..."

cmake -S . -B ./build-debug \
    -DBUILD_DEBUG=ON \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_CXX_FLAGS="-g -O0 -Wall -Wextra -pedantic" \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake --build ./build-debug -j$(nproc)
cmake --install ./build-debug
