add_executable(tests TestSuite.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread backend)
target_include_directories(tests PUBLIC "${PROJECT_SOURCE_DIR}/src/Backend")