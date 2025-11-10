cmake_minimum_required(VERSION 3.10)
project(mazes CXX)

set(CMAKE_CXX_STANDAED 17)
set(CMAKE_CXX_STANDAED_REQUIRED ON)

add_executable(main src/main.cpp)

target_include_directories(main PUBLIC include)