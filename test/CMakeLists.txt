include(GoogleTest)


add_executable(BinarySearchTest BinarySearchTest.cpp)
target_link_libraries(BinarySearchTest gtest gtest_main)
gtest_add_tests(TARGET BinarySearchTest)

add_executable(SelectionSortTest SelectionSortTest.cpp)
target_link_libraries(SelectionSortTest gtest gtest_main)
gtest_add_tests(TARGET SelectionSortTest)

add_executable(QuickSortTest QuickSortTest.cpp)
target_link_libraries(QuickSortTest gtest gtest_main)
gtest_add_tests(TARGET QuickSortTest)

add_executable(RecursiveTest RecursiveTest.cpp)
target_link_libraries(RecursiveTest gtest gtest_main)
gtest_add_tests(TARGET RecursiveTest)

add_executable(DijkstraTest DijkstraTest.cpp)
target_link_libraries(DijkstraTest gtest gtest_main)
gtest_add_tests(TARGET DijkstraTest)
