cmake_minimum_required(VERSION 3.15)

# Project name + C++ standard
project(TextAdventure LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# Define the executable
add_executable(text_adventure ${SOURCES})

# Add include directory so headers are found
target_include_directories(text_adventure PRIVATE include)
