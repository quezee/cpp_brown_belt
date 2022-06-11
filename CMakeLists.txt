cmake_minimum_required(VERSION 2.8)
project(bus_db)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

include_directories(include)
set(sources main.cpp src/bus_db.cpp src/route.cpp)

add_executable (main ${sources})
