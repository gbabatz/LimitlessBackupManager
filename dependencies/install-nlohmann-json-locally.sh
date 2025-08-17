# this is a header only library
# it is included in the project already - this script is for educatinoal purposes only

# cd ~ 
# git clone https://github.com/nlohmann/json.git
cd $LBM_ROOT
mkdir -p external/nlohmann-json/include/nlohmann
cp -r ~/json/include/nlohmann/* external/nlohmann-json/include/nlohmann/

# then, update the include directories in the CMakeLists.txt
