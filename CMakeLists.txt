cmake_minimum_required(VERSION 3.14)
project(ProjectVictor)
# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_policy(SET CMP0135 NEW)
include(FetchContent)
FetchContent_Declare(googletest
URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
# For Linux: This line is not needed, but it does not harm either
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# Create a library with some code to test
add_library(u_very_long 
    src/add_sub.cpp 
    src/eql.cpp 
    src/mul_div_mod.cpp
    src/bit_man.cpp)
# Tell CMake where to find the header files for the library
target_include_directories(u_very_long PUBLIC include)
# Create an executable that runs the tests
add_executable(u_very_long_test 
    tests/test_add_sub.cpp 
    tests/test_eql.cpp 
    tests/test_mul_div_mod.cpp
    tests/test_bit_man.cpp)
# Link the executable to GoogleTest and the library to test
target_link_libraries(u_very_long_test gtest_main u_very_long)

target_compile_options(u_very_long PRIVATE -mbmi2)
# Discover and register the tests with CTest
include(GoogleTest)
gtest_discover_tests(u_very_long_test)