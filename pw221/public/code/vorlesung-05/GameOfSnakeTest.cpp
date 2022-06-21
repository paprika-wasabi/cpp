// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <gtest/gtest.h>
#include "./GameOfSnake.h"

// _____________________________________________________________________________
TEST(GameOfSnakeTest, constructor) {
  GameOfSnake gameOfSnake(40, 80);
  ASSERT_EQ(gameOfSnake.speed_, 10);
  ASSERT_EQ(gameOfSnake.dirRow_, 0);
  ASSERT_EQ(gameOfSnake.dirCol_, 1);
}

// _____________________________________________________________________________
TEST(GameOfSnakeTest, moveSnake) {
  GameOfSnake gameOfSnake(40, 80);
  ASSERT_EQ(gameOfSnake.dirRow_, 0);
  ASSERT_EQ(gameOfSnake.dirCol_, 1);
  gameOfSnake.headRow_ = 10;
  gameOfSnake.headCol_ = 20;
  gameOfSnake.moveSnake();
  ASSERT_EQ(gameOfSnake.headRow_, 10);
  ASSERT_EQ(gameOfSnake.headCol_, 21);
}
