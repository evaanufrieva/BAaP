cmake_minimum_required(VERSION 3.16)
project(LR6)


#set(CMAKE_CXX_CPPCHECK "cppcheck")
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")
set(FILE_NAME_CPP "main.cpp")
set(CPP_SOURCES Task_1 Task_2 Task_3)
set(SANITIZER "address;thread")


include_directories(include)

add_executable(Task_1 Task_1/main.cpp Task_1/even_groups.cpp)
add_executable(Task_2 Task_2/main.cpp Task_2/substr.cpp)
add_executable(Task_3 Task_3/main.cpp Task_3/inplace.cpp)

# --- Google Test ---
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(runTests tests/gtests.cpp Task_1/even_groups.cpp Task_2/substr.cpp Task_3/inplace.cpp)
target_link_libraries(runTests GTest::GTest GTest::Main)
gtest_discover_tests(runTests)
