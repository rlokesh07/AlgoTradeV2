
cmake_minimum_required(VERSION 3.16)
project(my_project)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable CPPHTTPLIB_OPENSSL_SUPPORT
add_compile_definitions(CPPHTTPLIB_OPENSSL_SUPPORT)

# Add include directory (e.g., where httplib.h and json.hpp live)
include_directories(include)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Collect source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Define the executable
add_executable(my_project ${SOURCES})

# Link OpenSSL and pthread
target_link_libraries(my_project OpenSSL::SSL OpenSSL::Crypto pthread)

