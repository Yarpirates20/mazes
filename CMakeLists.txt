cmake_minimum_required(VERSION 3.10)
project(mazes CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(main src/main.cpp)
target_include_directories(main PUBLIC src)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test executable
add_executable(tests tests/CellFunctionalityTests.cpp src/Cell.cpp)
target_include_directories(tests PUBLIC src)
target_link_libraries(tests gtest_main)

add_test(NAME test1 COMMAND tests)