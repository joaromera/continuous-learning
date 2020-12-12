cmake_minimum_required(VERSION 3.17)
project(day04)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(day04
        ctre.hpp
        input.txt
        main.cpp)
