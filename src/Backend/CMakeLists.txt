file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/Commands/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/Commands/*.h)
add_library(backend SHARED ${SRC})

target_link_libraries(backend types)
target_include_directories(backend PUBLIC "${PROJECT_SOURCE_DIR}/src/Types")