# include(CTest)
# Set a minimum version of CMake to be used, depending on the syntax of the CMakeLists files
cmake_minimum_required(VERSION 2.8.9)

# Give this project a name.
project (CMake-test)

# CMake subdirectories to include for these libraries.
# subdirs(src)

# Add definition for math library
add_library(math src/math.cc)

# Add definition for test  binary
add_executable(CMake-test src/main.cc)
target_link_libraries(CMake-test math)

# Third-party library
include(ExternalProject)
ExternalProject_Add(googletest
    PREFIX "${CMAKE_BINARY_DIR}/lib"
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG "master"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/lib/installed
)

# Prevent build on all targets build
set_target_properties(googletest PROPERTIES EXCLUDE_FROM_ALL TRUE)

# Define ${CMAKE_INSTALL_...} variables
include(GNUInstallDirs)

# Specify where third-party libraries are located
link_directories(${CMAKE_BINARY_DIR}/lib/installed/${CMAKE_INSTALL_LIBDIR})
include_directories(${CMAKE_BINARY_DIR}/lib/installed/${CMAKE_INSTALL_INCLUDEDIR})

# This is required for googletest
find_package(Threads REQUIRED)

# Test
add_executable(math_test test/math_test.cc)
target_link_libraries(math_test math gtest Threads::Threads)


# Make sure third-party is built before executable
add_dependencies(math_test googletest)
set_target_properties(math_test PROPERTIES EXCLUDE_FROM_ALL TRUE)
