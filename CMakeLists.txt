cmake_minimum_required(VERSION 3.10)

project(IneptLogger)

# Set the C++ standard to the latest available (currently C++20)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_BINARY_DIR "../lib")

# Recursively find all source and header files for IneptLogger library
file(GLOB_RECURSE headers inc/*.h)
file(GLOB_RECURSE sources src/*.cpp)

# Add IneptLoggerTest project
add_subdirectory("tests")

# Create the library
add_library(IneptLogger STATIC ${headers} ${sources})

# Add include directories for headers
target_include_directories(IneptLogger PUBLIC inc)