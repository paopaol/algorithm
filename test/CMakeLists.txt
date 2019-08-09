include(GoogleTest)


add_executable(BinarySearchTest BinarySearchTest.cpp)
target_link_libraries(BinarySearchTest gtest gtest_main)
gtest_add_tests(TARGET BinarySearchTest)

add_executable(SelectionSortTest SelectionSortTest.cpp)
target_link_libraries(SelectionSortTest gtest gtest_main)
gtest_add_tests(TARGET SelectionSortTest)
