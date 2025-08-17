# this is a header only library
# it is included in the project already - this script is for educatinoal purposes only

cd $LBM_ROOT
mkdir -p external/cxxopts/include
curl -o external/cxxopts/include/cxxopts.hpp https://raw.githubusercontent.com/jarro2783/cxxopts/refs/tags/v3.3.1/include/cxxopts.hpp

# then, update the include directories in the CMakeLists.txt