#include <algorithm/recursive/example.h>
#include <gtest/gtest.h>
#include <gtest/internal/gtest-internal.h>

TEST(RecursiveTest, squareIs1680x640_findMaxSquare_maxSquareIs80x80) {
  int maxWidth = algorithm::findMaxSquare(1680, 640);
  EXPECT_EQ(maxWidth, 80);
}

TEST(RecursiveTest, sumArray_works) {
  std::vector<int> v = {1, 2, 3, 4};
  int sum = algorithm::sumArray(v.begin(), v.end());
  EXPECT_EQ(sum, 10);
}
