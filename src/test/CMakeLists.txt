add_executable(test test.cpp)
target_link_libraries(test ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)