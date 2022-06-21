// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <gtest/gtest.h>
#include "./GameOfLife.h"

// _____________________________________________________________________________
TEST(GameOfLifeTest, gliderTest) {
  putGlider(0, 0);
  bool expected[3][3] = { {0, 0, 1}, {1, 0, 1}, {0, 1, 1} };
  for (int row = 0; row < 3; ++row) {
    for (int col = 0; col < 3; ++col) {
      ASSERT_EQ(cells[row][col], expected[row][col]) << row << ", " << col;
    }
  }
}
