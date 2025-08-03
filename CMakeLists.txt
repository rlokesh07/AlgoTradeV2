cmake_minimum_required(VERSION 3.16)
project(my_project)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory so headers can be found with "my_project/foo.hpp"
include_directories(include)

# Collect source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Define the executable
add_executable(my_project ${SOURCES})
