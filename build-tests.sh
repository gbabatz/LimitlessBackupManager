#!/usr/bin/bash

echo "Building TEST mode..."

mkdir -p ./build/tests

cmake -S . -B ./build/tests \
    -DBUILD_MODE=TEST \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build ./build/tests #-j$(nproc)
echo "Test build complete."