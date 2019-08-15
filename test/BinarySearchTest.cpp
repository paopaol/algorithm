
#include <algorithm/binarySearch.h>
#include <gtest/gtest.h>
#include <vector>

TEST(BinarySearch, vectorIsordered_searchInit_works) {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 6, 7, 8, 1000, 3000};
  bool found = algorithm::binarySearch(v, 7);
  EXPECT_EQ(found, true);
  found = algorithm::binarySearch(v, 9);
  EXPECT_EQ(found, false);
}
