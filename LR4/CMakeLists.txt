cmake_minimum_required(VERSION 3.10.0)
project(lr4task1 VERSION 0.1.0 LANGUAGES C CXX)

include_directories(Task_1)
include_directories(Task_2)
include_directories(Task_3)
include_directories(Task_4)
include_directories(Task_5)
include_directories(Task_6)

add_executable(task1 Task_1/main.cpp Task_1/shift.cpp)
add_executable(task2 Task_2/main.cpp Task_2/saddle.cpp)
add_executable(task3 Task_3/main.cpp Task_3/even.cpp)
add_executable(task4 Task_4/main.c Task_4/diagSum.c)
add_executable(task5 Task_5/main.c Task_5/saper.c)
add_executable(task6 Task_6/main.c Task_6/magicSqr.c)

include(CTest)
enable_testing()
find_package(GTest CONFIG REQUIRED)
add_executable(gtests_program tests/tests.cpp Task_1/shift.cpp Task_3/even.cpp Task_2/saddle.cpp Task_4/diagSum.c Task_5/saper.c Task_6/magicSqr.c)

target_link_libraries(gtests_program PRIVATE GTest::gtest GTest::gtest_main)
add_test(NAME all_tests COMMAND gtests_program)

