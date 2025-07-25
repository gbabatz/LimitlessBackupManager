#!/bin/sh

cd ~/
git clone https://github.com/gabime/spdlog.git
cd spdlog && mkdir build && cd build
cmake .. && cmake --build .
cmake --install . 