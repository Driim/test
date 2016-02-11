cmake_minimum_required(VERSION 2.8)
project(Test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES codec.cpp codec.h)
add_executable(ya-test ${SOURCE_FILES} main.cpp)
add_executable(unit-test ${SOURCE_FILES} unit-test.cpp)