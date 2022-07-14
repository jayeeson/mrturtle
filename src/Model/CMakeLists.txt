file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/../Controller/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../Controller/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/../Controller/Commands/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/../Controller/Commands/*.h)
add_library(model SHARED ${SRC})

target_link_libraries(model types Qt5::Core)
target_include_directories(model PUBLIC "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/src/Model"
  "${PROJECT_SOURCE_DIR}/src/Types"
  "${PROJECT_SOURCE_DIR}/src/Controller"
  "${PROJECT_SOURCE_DIR}/src/Controller/Commands")