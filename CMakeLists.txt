cmake_minimum_required(VERSION 3.5)
project(property)

set(CMAKE_CXX_STANDARD 20)
include_directories(src, lib)
add_executable(property
        src/property.h
        src/main.cpp
        )
