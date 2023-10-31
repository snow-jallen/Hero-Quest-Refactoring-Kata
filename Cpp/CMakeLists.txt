cmake_minimum_required(VERSION 3.20)

project(HeroQuest VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)

enable_testing()

set(SRC_LIB_NAME src)
set(SOURCES quest.cpp)
add_library(${SRC_LIB_NAME} ${SOURCES})
target_sources(${SRC_LIB_NAME} PRIVATE ${SOURCES})
target_include_directories(${SRC_LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(quest main.cpp)
target_link_libraries(quest ${SRC_LIB_NAME})
set(TEST_NAME quest_test)

include(FetchContent)
set(SOURCE_FILES quest_catch.cpp)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.10
        GIT_SHALLOW    1)
FetchContent_MakeAvailable(Catch2)

add_executable(${TEST_NAME})
target_sources(${TEST_NAME} PRIVATE ${SOURCE_FILES})
target_link_libraries(${TEST_NAME} ${SRC_LIB_NAME} Catch2::Catch2)
add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
