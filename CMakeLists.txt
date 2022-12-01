cmake_minimum_required(VERSION 3.23)
project(aoc2022)

set(CMAKE_CXX_STANDARD 20)

include_directories("./days")
add_executable(aoc2022 main.cpp days/day1.cpp days/day1.h)
