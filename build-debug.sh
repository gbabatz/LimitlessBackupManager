#!/usr/bin/bash

echo "Building DEBUG mode..."

mkdir -p ./build/debug

cmake -S . -B ./build/debug \
    -DBUILD_MODE=DEBUG \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build ./build/debug -j$(nproc)
cmake --install ./build/debug

if [ $? -ne 0 ]; then
    echo "Debug build failed."
    exit 1
fi

echo "Debug build complete."
