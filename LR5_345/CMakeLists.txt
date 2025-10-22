cmake_minimum_required(VERSION 3.14)
project(LR5_345)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

# =========================
# Исполняемые файлы
# =========================
add_executable(task3
    ${CMAKE_SOURCE_DIR}/LR5_3/main.cpp
    ${CMAKE_SOURCE_DIR}/LR5_3/diag.cpp
)

add_executable(task4
    ${CMAKE_SOURCE_DIR}/LR5_4/main.cpp
    ${CMAKE_SOURCE_DIR}/LR5_4/nullElem.cpp
)

add_executable(task5
    ${CMAKE_SOURCE_DIR}/LR5_5/main.cpp
    ${CMAKE_SOURCE_DIR}/LR5_5/odd.cpp
)

# =========================
# GoogleTest
# =========================
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# =========================
# Тесты
# =========================
add_executable(tests
    ${CMAKE_SOURCE_DIR}/tests/tests.cpp
    ${CMAKE_SOURCE_DIR}/LR5_3/diag.cpp
    ${CMAKE_SOURCE_DIR}/LR5_4/nullElem.cpp
    ${CMAKE_SOURCE_DIR}/LR5_5/odd.cpp
)

target_link_libraries(tests PRIVATE gtest_main)
target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR}/include)

include(GoogleTest)
gtest_discover_tests(tests)
