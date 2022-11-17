file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h )
add_library(utility SHARED ${SRC})

target_link_libraries(utility)
target_include_directories(utility PUBLIC "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/src/Utility")