#!/usr/bin/bash

echo "Building DEBUG mode..."

mkdir -p ./build/debug

cmake -S . -B ./build/debug \
    -DBUILD_MODE=DEBUG \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build ./build/debug -j$(nproc)
cmake --install ./build/debug
echo "Debug build complete."
