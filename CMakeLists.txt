cmake_minimum_required(VERSION 2.8)
project(bus_db)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

include_directories(include)
set(sources src/bus_dp.cpp src/route.cpp)

add_subdirectory(googletest)

add_executable (main main.cpp ${sources})
add_executable (tests tests.cpp ${sources})
target_link_libraries(tests gtest_main)