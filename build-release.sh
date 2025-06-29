#!/usr/bin/bash

rm -rf ./build
mkdir -p ./build && cd ./build
cmake -S .. -B . -DCMAKE_BUILD_TYPE=Release
cmake --build .
cmake --install .