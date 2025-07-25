#!/bin/sh

# move to working directory
cd ~/

# download
git clone https://github.com/google/googletest.git

# build
cd googletest
mkdir build
cd build
cmake ..
make

# install
sudo cp -r ~/googletest/googlemock/include/gmock /usr/local/include/gmock
sudo cp -r ~/googletest/googletest/include/gtest /usr/local/include/gtest
sudo mkdir /usr/local/lib/gtest; sudo cp -r ~/googletest/build/lib/libgtest*.a /usr/local/lib/gtest/
sudo mkdir /usr/local/lib/gmock; sudo cp -r ~/googletest/build/lib/libgmock*.a /usr/local/lib/gmock/