include(GoogleTest)


add_executable(binary_search_test binary_search_test.cpp)
target_link_libraries(binary_search_test gtest gtest_main)

gtest_add_tests(TARGET binary_search_test)
