add_executable(test test.cpp)
target_link_libraries(test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread src_lib)
target_include_directories(test PUBLIC "${PROJECT_SOURCE_DIR}/src")