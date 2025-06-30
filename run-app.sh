#!/usr/bin/bash

# Default to release, but allow override
BUILD_TYPE=${1:-release}
echo "Running ${BUILD_TYPE} build..."
./build/install/${BUILD_TYPE}/bin/lbm

# or 
# ./build/${BUILD_TYPE}/bin/lbm