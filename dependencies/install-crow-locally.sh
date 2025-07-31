#!/bin/sh

# Crow is a header only C++ micro web framework for RESTful APIs.

cd ~/
git clone https://github.com/CrowCpp/Crow.git
cd Crow && mkdir build && cd build
cmake .. -DCROW_BUILD_EXAMPLES=OFF \
         -DCROW_BUILD_TESTS=OFF \
         -DASIO_INCLUDE_DIR=/usr/local/include/asio \ # IMPORTANT - Custom ASIO path
         && cmake --build .
sudo cmake --install . 

