# Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSC VERSION 0.1.0)

set(CMAKE_VERBOSE_MAKEFILE ON)
add_executable(mpags-cipher mpags-cipher.cpp)