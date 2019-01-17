# include(CTest)
# Set a minimum version of CMake to be used, depending on the syntax of the CMakeLists files
cmake_minimum_required(VERSION 2.8.9)
# Give this project a name.
project (test)
# CMake subdirectories to include for these libraries.
# subdirs(src)
# create the executable
add_executable(test src/test.cc)
