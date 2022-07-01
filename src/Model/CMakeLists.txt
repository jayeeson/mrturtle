file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
add_library(model SHARED ${SRC})

target_link_libraries(model types Qt5::Core)
target_include_directories(model PUBLIC "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/src/Types")