#include <algorithm/QuickSort.h>
#include <gtest/gtest.h>

TEST(QuickSortTest, vector2IsUnOrdered_quickSort_vectorIsOrdered) {
  std::vector<int> unorderedList = {5, 1};
  std::vector<int> orderedList = {1, 5};

  algorithm::quickSort(unorderedList.begin(), unorderedList.end());
  EXPECT_EQ(
      std::equal(orderedList.begin(), orderedList.end(), unorderedList.begin()),
      true);
}

TEST(QuickSortTest, vector3IsUnOrdered_quickSort_vectorIsOrdered) {
  std::vector<int> unorderedList = {5, 1, -2};
  std::vector<int> orderedList = {-2, 1, 5};

  algorithm::quickSort(unorderedList.begin(), unorderedList.end());
  EXPECT_EQ(
      std::equal(orderedList.begin(), orderedList.end(), unorderedList.begin()),
      true);
}

TEST(QuickSortTest, vectorManayIsUnOrdered_quickSort_vectorIsOrdered) {
  std::vector<int> unorderedList = {5, 1, -2, 9, -10, 5, 100};
  std::vector<int> orderedList = {-10, -2, 1, 5, 5, 9, 100};

  algorithm::quickSort(unorderedList.begin(), unorderedList.end());
  EXPECT_EQ(
      std::equal(orderedList.begin(), orderedList.end(), unorderedList.begin()),
      true);
}
