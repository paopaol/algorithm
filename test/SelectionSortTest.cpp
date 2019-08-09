#include <algorithm/SelectionSort.h>
#include <gtest/gtest.h>

TEST(SelectionSortTest, vectorIsUnOrdered_selectionSort_vectorIsOrdered) {
  std::vector<int> unorderedList = {1, 5, -13, 4, 100, 9};
  std::vector<int> orderedList = {-13, 1, 4, 5, 9, 100};

  algorithm::selectionSort(unorderedList);
  EXPECT_EQ(
      std::equal(orderedList.begin(), orderedList.end(), unorderedList.begin()),
      true);
}
