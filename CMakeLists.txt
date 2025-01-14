# How to use:
# cmake -S . -B build
# cd build
# make

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "g++")

project(
  RandomTreeProject
  VERSION 1.0
  LANGUAGES CXX
)

add_executable(randomTreeProject
  "${CMAKE_CURRENT_SOURCE_DIR}/src/data-structure/tree.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)

target_include_directories(randomTreeProject
  PRIVATE
  src/data-structure
  src
)

target_compile_options(randomTreeProject
  PRIVATE
  -Wall -Wextra -pedantic -g -O2
)

set_target_properties(randomTreeProject
  PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)