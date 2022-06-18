set(HEADERS)
set(HEADER_DIRECTORIES src/include)
set(SRC main.cpp
    qml/qml.qrc
)

add_executable(helloworld
    ${SRC}
    ${HEADERS}
)

target_include_directories(helloworld PRIVATE ${HEADER_DIRECTORIES})
target_link_libraries(helloworld Qt5::Core Qt5::Widgets Qt5::Quick Qt5::Qml)
set_target_properties(Qt5::Quick PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")


add_subdirectory(test)