cmake_minimum_required(VERSION 3.26)
project(MazesTests)

add_executable(runUnitTests CellTest.cpp ../src/Cell.cpp GridTest.cpp ../src/Grid.cpp)

target_include_directories(runUnitTests PRIVATE ${CMAKE_SOURCE_DIR}/src/include)
target_link_libraries(runUnitTests GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(runUnitTests)

