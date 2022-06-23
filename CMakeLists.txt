cmake_minimum_required(VERSION 3.1.0)

project(helloworld
    VERSION 1.0.0
    DESCRIPTION ""
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS  Core Widgets Qml Quick REQUIRED)
find_package(Qt5QuickCompiler)
qtquick_compiler_add_resources(RESOURCES src/qml/qml.qrc)
find_package(GTest)
include_directories(${GTEST_INCLUDE_DIRS})

enable_testing()


add_subdirectory(src)
add_subdirectory(test)

add_test(NAME TEST_SUITE COMMAND tests )