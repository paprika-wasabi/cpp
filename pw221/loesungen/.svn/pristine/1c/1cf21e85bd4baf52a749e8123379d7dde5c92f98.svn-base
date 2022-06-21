// Copyright 2020, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Claudius Korzen <korzen@cs.uni-freiburg.de>.
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.

// IMPORTANT:
// You are not required to write this many tests in your solution.

#include <gtest/gtest.h>
#include "./GameOfLife.h"

TEST(GameOfLife, numAliveNeighboursSingle) {
  GameOfLife g;
  // Test empty field and border handling.
  for (int x = 0; x < GameOfLife::MAX_SIZE; ++x) {
    for (int y = 0; y < GameOfLife::MAX_SIZE; ++y) {
      ASSERT_EQ(0, g.numAliveNeighbours(x, y));
    }
  }

  // Test for only neigbours are counted.
  (*g.previousGrid_)[2][1] = true;
  ASSERT_EQ(1, g.numAliveNeighbours(1, 0));
  ASSERT_EQ(1, g.numAliveNeighbours(2, 0));
  ASSERT_EQ(1, g.numAliveNeighbours(3, 0));
  ASSERT_EQ(1, g.numAliveNeighbours(1, 1));
  ASSERT_EQ(0, g.numAliveNeighbours(2, 1));
  ASSERT_EQ(1, g.numAliveNeighbours(3, 1));
  ASSERT_EQ(1, g.numAliveNeighbours(1, 2));
  ASSERT_EQ(1, g.numAliveNeighbours(2, 2));
  ASSERT_EQ(1, g.numAliveNeighbours(3, 2));
}

TEST(GameOfLife, numAliveNeighboursMultiple) {
  GameOfLife g;

  // Test for only neigbours are counted.
  (*g.previousGrid_)[4][4] = true;
  (*g.previousGrid_)[4][5] = true;
  (*g.previousGrid_)[5][4] = true;
  (*g.previousGrid_)[5][5] = true;
  ASSERT_EQ(1, g.numAliveNeighbours(3, 3));
  ASSERT_EQ(2, g.numAliveNeighbours(3, 4));
  ASSERT_EQ(2, g.numAliveNeighbours(3, 5));
  ASSERT_EQ(1, g.numAliveNeighbours(3, 6));
  ASSERT_EQ(2, g.numAliveNeighbours(4, 3));
  ASSERT_EQ(3, g.numAliveNeighbours(4, 4));
  ASSERT_EQ(3, g.numAliveNeighbours(4, 5));
  ASSERT_EQ(2, g.numAliveNeighbours(4, 6));
  ASSERT_EQ(2, g.numAliveNeighbours(5, 3));
  ASSERT_EQ(3, g.numAliveNeighbours(5, 4));
  ASSERT_EQ(3, g.numAliveNeighbours(5, 5));
  ASSERT_EQ(2, g.numAliveNeighbours(5, 6));
  ASSERT_EQ(1, g.numAliveNeighbours(6, 3));
  ASSERT_EQ(2, g.numAliveNeighbours(6, 4));
  ASSERT_EQ(2, g.numAliveNeighbours(6, 5));
  ASSERT_EQ(1, g.numAliveNeighbours(6, 6));
}

TEST(GameOfLife, processUserInputQuit) {
  GameOfLife g;
  UserInput input;
  input.isMouseclick_ = false;
  input.keycode_ = 'q';
  ASSERT_FALSE(g.processUserInput(input));
}

TEST(GameOfLife, processUserInputSpace) {
  GameOfLife g;
  g.isRunning_ = false;
  UserInput input;
  input.isMouseclick_ = false;
  input.keycode_ = ' ';
  ASSERT_TRUE(g.processUserInput(input));
  ASSERT_TRUE(g.isRunning_);
  ASSERT_TRUE(g.processUserInput(input));
  ASSERT_FALSE(g.isRunning_);
}

TEST(GameOfLife, processUserInputSmallS) {
  GameOfLife g;
  g.numSteps_ = 0;
  UserInput input;
  input.isMouseclick_ = false;
  input.keycode_ = 's';
  ASSERT_TRUE(g.processUserInput(input));
  ASSERT_EQ(g.numSteps_, 1);
}

TEST(GameOfLife, processUserInputSmallG) {
  GameOfLife g;
  // Glider is 3x3

  g.lastClickedX_ = 3;
  g.lastClickedY_ = 3;
  UserInput input;
  input.isMouseclick_ = false;
  input.keycode_ = 'g';
  ASSERT_TRUE(g.processUserInput(input));
  int count = 0;
  for (int x = g.lastClickedX_; x < g.lastClickedX_ + 3; ++x) {
    for (int y = g.lastClickedY_; y < g.lastClickedY_ + 3; ++y) {
      count += (*g.currentGrid_)[x][y];
    }
  }
  ASSERT_EQ(5, count);
}

TEST(GameOfLife, processUserInputSmallR) {
  GameOfLife g;
  UserInput input;
  input.isMouseclick_ = false;
  input.keycode_ = 'r';
  ASSERT_TRUE(g.processUserInput(input));
  int count = 0;
  for (int x = 0; x < GameOfLife::MAX_SIZE; ++x) {
    for (int y = 0; y < GameOfLife::MAX_SIZE; ++y) {
      count += (*g.currentGrid_)[x][y];
    }
  }
  // Chance is 1/5, so we shall have more than 1/6 ...
  ASSERT_LT((GameOfLife::MAX_SIZE * GameOfLife::MAX_SIZE / 6), count);
  // but less than 1/4 of total cells numAlive.
  ASSERT_GT((GameOfLife::MAX_SIZE * GameOfLife::MAX_SIZE / 4), count);
}

TEST(GameOfLife, updateStateEmptyGrid) {
  // Empty stays empty
  GameOfLife g;
  g.updateState();
  ASSERT_EQ(0, g.numLivingCells_);
  for (int x = 0; x < GameOfLife::MAX_SIZE; ++x) {
    for (int y = 0; y < GameOfLife::MAX_SIZE; ++y) {
      ASSERT_FALSE((*g.previousGrid_)[x][y]);
      ASSERT_FALSE((*g.currentGrid_)[x][y]);
    }
  }
}

TEST(GameOfLife, updateStateStaticObject) {
  GameOfLife g;
  (*g.currentGrid_)[4][4] = 1;
  (*g.currentGrid_)[4][5] = 1;
  (*g.currentGrid_)[5][4] = 1;
  (*g.currentGrid_)[5][5] = 1;
  g.updateState();
  ASSERT_EQ(4, g.numLivingCells_);
  ASSERT_FALSE((*g.currentGrid_)[3][3]);
  ASSERT_FALSE((*g.currentGrid_)[3][4]);
  ASSERT_FALSE((*g.currentGrid_)[3][5]);
  ASSERT_FALSE((*g.currentGrid_)[3][6]);
  ASSERT_FALSE((*g.currentGrid_)[4][3]);
  ASSERT_TRUE((*g.currentGrid_)[4][4]);
  ASSERT_TRUE((*g.currentGrid_)[4][5]);
  ASSERT_FALSE((*g.currentGrid_)[4][6]);
  ASSERT_FALSE((*g.currentGrid_)[5][3]);
  ASSERT_TRUE((*g.currentGrid_)[5][4]);
  ASSERT_TRUE((*g.currentGrid_)[5][5]);
  ASSERT_FALSE((*g.currentGrid_)[5][6]);
  ASSERT_FALSE((*g.currentGrid_)[6][3]);
  ASSERT_FALSE((*g.currentGrid_)[6][4]);
  ASSERT_FALSE((*g.currentGrid_)[6][5]);
  ASSERT_FALSE((*g.currentGrid_)[6][6]);
}

TEST(GameOfLife, updateStateP2Blinker) {
  // Tests updateState function with a period 2 blinker.
  GameOfLife g;

  (*g.currentGrid_)[4][4] = 1;
  (*g.currentGrid_)[4][5] = 1;
  (*g.currentGrid_)[4][6] = 1;
  // |
  g.updateState();
  ASSERT_EQ(3, g.numLivingCells_);
  ASSERT_FALSE((*g.currentGrid_)[3][4]);
  ASSERT_TRUE((*g.currentGrid_)[3][5]);
  ASSERT_FALSE((*g.currentGrid_)[3][6]);
  ASSERT_FALSE((*g.currentGrid_)[4][4]);
  ASSERT_TRUE((*g.currentGrid_)[4][5]);
  ASSERT_FALSE((*g.currentGrid_)[4][6]);
  ASSERT_FALSE((*g.currentGrid_)[5][4]);
  ASSERT_TRUE((*g.currentGrid_)[5][5]);
  ASSERT_FALSE((*g.currentGrid_)[5][6]);
  // -
  g.updateState();
  ASSERT_EQ(3, g.numLivingCells_);
  ASSERT_FALSE((*g.currentGrid_)[3][4]);
  ASSERT_FALSE((*g.currentGrid_)[3][5]);
  ASSERT_FALSE((*g.currentGrid_)[3][6]);
  ASSERT_TRUE((*g.currentGrid_)[4][4]);
  ASSERT_TRUE((*g.currentGrid_)[4][5]);
  ASSERT_TRUE((*g.currentGrid_)[4][6]);
  ASSERT_FALSE((*g.currentGrid_)[5][4]);
  ASSERT_FALSE((*g.currentGrid_)[5][5]);
  ASSERT_FALSE((*g.currentGrid_)[5][6]);
}

TEST(GameOfLife, isLegalPosition) {
  GameOfLife g;
  int maxSize = GameOfLife::MAX_SIZE;
  ASSERT_TRUE(g.isLegalPosition(0, 0));
  ASSERT_TRUE(g.isLegalPosition(0, 15));
  ASSERT_TRUE(g.isLegalPosition(15, 0));
  ASSERT_TRUE(g.isLegalPosition(15, 15));
  ASSERT_TRUE(g.isLegalPosition(15, maxSize - 1));
  ASSERT_TRUE(g.isLegalPosition(maxSize - 1, 15));
  ASSERT_TRUE(g.isLegalPosition(maxSize - 1, maxSize - 1));

  ASSERT_FALSE(g.isLegalPosition(-1, 0));
  ASSERT_FALSE(g.isLegalPosition(-18, 5));
  ASSERT_FALSE(g.isLegalPosition(0, -1));
  ASSERT_FALSE(g.isLegalPosition(5, -13));
  ASSERT_FALSE(g.isLegalPosition(5, maxSize));
  ASSERT_FALSE(g.isLegalPosition(maxSize, maxSize));
  ASSERT_FALSE(g.isLegalPosition(maxSize, 0));
}

