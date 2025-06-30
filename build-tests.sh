#!/usr/bin/bash

# rm -rf ./build-test
mkdir -p ./build-test

echo "Building TEST mode..."

cmake -S . -B ./build-test -DBUILD_TESTS=ON
cmake --build ./build-test -j$(nproc)