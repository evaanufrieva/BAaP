cmake_minimum_required(VERSION 3.28)
project(LR5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

# ---------------------------
# Статическая библиотека
# ---------------------------
file(GLOB LR5_STATIC_SRC "src/LR5_StaticLib/*.cpp")
add_library(LR5_StaticLib STATIC ${LR5_STATIC_SRC})
target_include_directories(LR5_StaticLib PUBLIC ${CMAKE_SOURCE_DIR}/include)
set_target_properties(LR5_StaticLib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# ---------------------------
# task1
# ---------------------------
add_executable(task1 src/LR5_1/main.cpp)
target_link_libraries(task1 PRIVATE LR5_StaticLib)
set_target_properties(task1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# ---------------------------
# Динамическая библиотека
# ---------------------------
file(GLOB LR5_DYNAMIC_SRC "src/LR5_DynamicLib/*.cpp")
add_library(LR5_DL SHARED ${LR5_DYNAMIC_SRC})
target_include_directories(LR5_DL PUBLIC ${CMAKE_SOURCE_DIR}/include)
set_target_properties(LR5_DL PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# ---------------------------
# task2
# ---------------------------
add_executable(task2 src/LR5_2/main.cpp)
target_link_libraries(task2 PRIVATE LR5_DL)
set_target_properties(task2 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    BUILD_RPATH "$ORIGIN"
    INSTALL_RPATH "$ORIGIN"
)

# ---------------------------
# Google Tests через FetchContent
# ---------------------------
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

enable_testing()

add_executable(gtests tests/gtest.cpp)
target_link_libraries(gtests PRIVATE LR5_StaticLib LR5_DL gtest_main)
set_target_properties(gtests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

add_test(NAME AllTests COMMAND gtests)


# cmake_minimum_required(VERSION 3.28)

# project(LR5)

# set(FILE_NAME "main.cpp")
# set(SOURCES Task_3 Task_4 Task_5)

# include_directories(include)
# include_directories(src/LR5_StaticLib1)

# include(FetchContent)
# FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)
# FetchContent_MakeAvailable(googletest)
# include(GoogleTest)

# enable_testing()
# add_executable(tests tests/gtest.cpp)
# target_link_libraries(tests GTest::gtest_main LR5_StaticLib1)
# target_link_directories(tests PUBLIC src/LR5_1/x64/Debug/)
# gtest_discover_tests(tests)
# add_custom_command(TARGET tests POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}\\src\\LR5_2\\x64\\Debug\\LR5_DynamicLib.dll ${PROJECT_BINARY_DIR}\\Debug)  

# foreach(SOURCE ${SOURCES})
#     add_executable(${SOURCE} src/${SOURCE}/${FILE_NAME})
#     target_include_directories(${SOURCE} PRIVATE include)
# endforeach(SOURCE ${SOURCES})