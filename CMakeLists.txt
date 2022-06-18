cmake_minimum_required(VERSION 3.1.0)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS)
set(HEADER_DIRECTORIES src/include)
set(SRC src/main.cpp
    src/qml.qrc
)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS  Core Widgets Qml Quick REQUIRED)
find_package(Qt5QuickCompiler)
qtquick_compiler_add_resources(RESOURCES example.qrc)

add_executable(helloworld
    ${SRC}
    ${HEADERS}
)

target_include_directories(helloworld PRIVATE ${HEADER_DIRECTORIES})
target_link_libraries(helloworld Qt5::Core Qt5::Widgets Qt5::Quick Qt5::Qml)
set_target_properties(Qt5::Quick PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
