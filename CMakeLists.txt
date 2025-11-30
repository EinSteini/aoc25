cmake_minimum_required(VERSION 3.16)
project(aoc2025)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(APPLE)
    message(STATUS "Building for Apple Silicon")
    add_compile_options(-O3 -march=armv8.4-a -mtune=apple-m1)
endif()

include_directories(${CMAKE_SOURCE_DIR})

file(GLOB DAY_DIRS "days/day*")

foreach(DAY ${DAY_DIRS})
    get_filename_component(DAY_NAME ${DAY} NAME)
    add_executable(${DAY_NAME} ${DAY}/main.cpp)
endforeach()
