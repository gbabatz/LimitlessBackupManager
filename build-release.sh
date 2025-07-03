#!/usr/bin/bash  

echo "Building RELEASE mode..."

mkdir -p ./build/release

cmake -S . -B ./build/release \
    -DBUILD_MODE=RELEASE \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON 
cmake --build ./build/release -j$(nproc)  
cmake --install ./build/release

if [ $? -ne 0 ]; then
    echo "Release build failed."
    exit 1
fi

echo "Release build complete."