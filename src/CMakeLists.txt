set(HEADER_DIRECTORIES Commands)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(src_lib ${SRC})

include_directories(${HEADER_DIRECTORIES})
target_link_libraries(src_lib Qt5::Core Qt5::Widgets Qt5::Quick Qt5::Qml)
set_target_properties(Qt5::Quick PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")


add_subdirectory(test)
