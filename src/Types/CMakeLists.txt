file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
add_library(types SHARED ${SRC})
target_link_libraries(types Qt5::Core)