#!/usr/bin/bash

echo "Running tests..."

export CTEST_OUTPUT_ON_FAILURE=1;
export GTEST_COLOR=yes;
ctest --test-dir ./build/tests --output-on-failure