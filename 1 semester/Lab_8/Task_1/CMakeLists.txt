cmake_minimum_required(VERSION 3.7)
project(Task_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -Wall")

set(SOURCE_FILES main.cpp)
add_executable(Task_1 ${SOURCE_FILES})