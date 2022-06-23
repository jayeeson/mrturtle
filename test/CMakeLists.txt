file(GLOB TEST_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(tests ${TEST_FILES})
target_link_libraries(tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread model)
target_include_directories(tests PUBLIC "${PROJECT_SOURCE_DIR}/src/Model")