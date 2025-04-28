cmake_minimum_required(VERSION 3.15)

# Project name and version
project(Utils VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(Utils main.cpp)

# Include directories
target_include_directories(Utils PRIVATE include_headers)