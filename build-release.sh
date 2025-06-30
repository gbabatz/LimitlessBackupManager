#!/usr/bin/bash

# rm -rf ./build
mkdir -p ./build

echo "Building RELEASE mode..."

cmake -S . -B ./build \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_CXX_FLAGS="-O3 -DNDEBUG -flto" \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake --build ./build -j$(nproc)
cmake --install ./build