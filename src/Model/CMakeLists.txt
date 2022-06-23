file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
add_library(model SHARED ${SRC})

target_link_libraries(model types)
target_include_directories(model PUBLIC "${PROJECT_SOURCE_DIR}/src/Types")