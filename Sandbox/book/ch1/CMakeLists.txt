cmake_minimum_required(VERSION 3.10)
project(test_ch1 CXX)

enable_testing()

find_package(GTest REQUIRED)

include(GoogleTest)

add_executable(test_ch1 test.cpp main.cpp)
target_link_libraries(test_ch1 GTest::GTest GTest::Main)

gtest_add_tests(TARGET test_ch1)