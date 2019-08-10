#include <algorithm/recursive/example.h>
#include <gtest/gtest.h>

TEST(FindMaxSquareTest, squareIs1680x640_findMaxSquare_maxSquareIs80x80) {
  int maxWidth = algorithm::findMaxSquare(1680, 640);
  EXPECT_EQ(maxWidth, 80);
}
