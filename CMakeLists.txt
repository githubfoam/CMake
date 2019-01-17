# include(CTest)
# Set a minimum version of CMake to be used, depending on the syntax of the CMakeLists files
cmake_minimum_required(VERSION 2.8.9)

# Give this project a name.
project (test)

# Add definition for math library
add_library(math src/math.cc)

# Add definition for test  binary
add_executable(CMake-test src/main.cc)
target_link_libraries(CMake-test math)
