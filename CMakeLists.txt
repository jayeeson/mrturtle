cmake_minimum_required(VERSION 3.1.0)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(HEADERS src/include/MainWindow.h
    src/include/RenderArea.h)
set(HEADER_DIRECTORIES src/include)
set(SRC src/main.cpp
    src/resources.qrc
    src/qml.qrc
)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

list(APPEND CMAKE_PREFIX_PATH /usr/lib/x86_64-linux-gnu/qt5/qml/QtQuick)

find_package(Qt5 COMPONENTS Widgets Qml Quick REQUIRED)


add_executable(helloworld
    ${SRC}
    ${HEADERS}
)

target_include_directories(helloworld PRIVATE ${HEADER_DIRECTORIES})
target_link_libraries(helloworld Qt5::Core Qt5::Widgets Qt5::Quick)
set_target_properties(Qt5::Quick PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
