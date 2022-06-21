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
  initGame();
  // Test empty field and border handling.
  for (int x = 0; x < MAX_SIZE; ++x) {
    for (int y = 0; y < MAX_SIZE; ++y) {
      ASSERT_EQ(0, numAliveNeighbours(x, y));
    }
  }

  // Test for only neigbours are counted.
  (*previousGrid)[2][1] = true;
  ASSERT_EQ(1, numAliveNeighbours(1, 0));
  ASSERT_EQ(1, numAliveNeighbours(2, 0));
  ASSERT_EQ(1, numAliveNeighbours(3, 0));
  ASSERT_EQ(1, numAliveNeighbours(1, 1));
  ASSERT_EQ(0, numAliveNeighbours(2, 1));
  ASSERT_EQ(1, numAliveNeighbours(3, 1));
  ASSERT_EQ(1, numAliveNeighbours(1, 2));
  ASSERT_EQ(1, numAliveNeighbours(2, 2));
  ASSERT_EQ(1, numAliveNeighbours(3, 2));
}

TEST(GameOfLife, numAliveNeighboursMultiple) {
  initGame();

  // Test for only neigbours are counted.
  (*previousGrid)[4][4] = true;
  (*previousGrid)[4][5] = true;
  (*previousGrid)[5][4] = true;
  (*previousGrid)[5][5] = true;
  ASSERT_EQ(1, numAliveNeighbours(3, 3));
  ASSERT_EQ(2, numAliveNeighbours(3, 4));
  ASSERT_EQ(2, numAliveNeighbours(3, 5));
  ASSERT_EQ(1, numAliveNeighbours(3, 6));
  ASSERT_EQ(2, numAliveNeighbours(4, 3));
  ASSERT_EQ(3, numAliveNeighbours(4, 4));
  ASSERT_EQ(3, numAliveNeighbours(4, 5));
  ASSERT_EQ(2, numAliveNeighbours(4, 6));
  ASSERT_EQ(2, numAliveNeighbours(5, 3));
  ASSERT_EQ(3, numAliveNeighbours(5, 4));
  ASSERT_EQ(3, numAliveNeighbours(5, 5));
  ASSERT_EQ(2, numAliveNeighbours(5, 6));
  ASSERT_EQ(1, numAliveNeighbours(6, 3));
  ASSERT_EQ(2, numAliveNeighbours(6, 4));
  ASSERT_EQ(2, numAliveNeighbours(6, 5));
  ASSERT_EQ(1, numAliveNeighbours(6, 6));
}

TEST(GameOfLife, processUserInputQuit) {
  ASSERT_FALSE(processUserInput('q'));
}

TEST(GameOfLife, processUserInputSpace) {
  isRunning = false;
  ASSERT_TRUE(processUserInput(' '));
  ASSERT_TRUE(isRunning);
  ASSERT_TRUE(processUserInput(' '));
  ASSERT_FALSE(isRunning);
}

TEST(GameOfLife, processUserInputSmallS) {
  initGame();
  numSteps = 0;
  ASSERT_TRUE(processUserInput('s'));
  ASSERT_EQ(numSteps, 1);
}

TEST(GameOfLife, processUserInputSmallG) {
  initGame();
  // Glider is 3x3

  lastClickedX = 3;
  lastClickedY = 3;
  ASSERT_TRUE(processUserInput('g'));
  int count = 0;
  for (int x = lastClickedX; x < lastClickedX + 3; ++x) {
    for (int y = lastClickedY; y < lastClickedY + 3; ++y) {
      count += (*currentGrid)[x][y];
    }
  }
  ASSERT_EQ(5, count);
}

TEST(GameOfLife, processUserInputSmallR) {
  initGame();
  ASSERT_TRUE(processUserInput('r'));
  int count = 0;
  for (int x = 0; x < MAX_SIZE; ++x) {
    for (int y = 0; y < MAX_SIZE; ++y) {
      count += (*currentGrid)[x][y];
    }
  }
  // Chance is 1/5, so we shall have more than 1/6 ...
  ASSERT_LT((MAX_SIZE * MAX_SIZE / 6), count);
  // but less than 1/4 of total cells numAlive.
  ASSERT_GT((MAX_SIZE * MAX_SIZE / 4), count);
}

TEST(GameOfLife, updateStateEmptyGrid) {
  // Empty stays empty
  initGame();
  updateState();
  ASSERT_EQ(0, numLivingCells);
  for (int x = 0; x < MAX_SIZE; ++x) {
    for (int y = 0; y < MAX_SIZE; ++y) {
      ASSERT_FALSE((*previousGrid)[x][y]);
      ASSERT_FALSE((*currentGrid)[x][y]);
    }
  }
}

TEST(GameOfLife, updateStateStaticObject) {
  initGame();
  (*currentGrid)[4][4] = 1;
  (*currentGrid)[4][5] = 1;
  (*currentGrid)[5][4] = 1;
  (*currentGrid)[5][5] = 1;
  updateState();
  ASSERT_EQ(4, numLivingCells);
  ASSERT_FALSE((*currentGrid)[3][3]);
  ASSERT_FALSE((*currentGrid)[3][4]);
  ASSERT_FALSE((*currentGrid)[3][5]);
  ASSERT_FALSE((*currentGrid)[3][6]);
  ASSERT_FALSE((*currentGrid)[4][3]);
  ASSERT_TRUE((*currentGrid)[4][4]);
  ASSERT_TRUE((*currentGrid)[4][5]);
  ASSERT_FALSE((*currentGrid)[4][6]);
  ASSERT_FALSE((*currentGrid)[5][3]);
  ASSERT_TRUE((*currentGrid)[5][4]);
  ASSERT_TRUE((*currentGrid)[5][5]);
  ASSERT_FALSE((*currentGrid)[5][6]);
  ASSERT_FALSE((*currentGrid)[6][3]);
  ASSERT_FALSE((*currentGrid)[6][4]);
  ASSERT_FALSE((*currentGrid)[6][5]);
  ASSERT_FALSE((*currentGrid)[6][6]);
}

TEST(GameOfLife, updateStateP2Blinker) {
  // Tests updateState function with a period 2 blinker.
  initGame();
  // -
  (*currentGrid)[4][4] = 1;
  (*currentGrid)[4][5] = 1;
  (*currentGrid)[4][6] = 1;
  // |
  updateState();
  ASSERT_EQ(3, numLivingCells);
  ASSERT_FALSE((*currentGrid)[3][4]);
  ASSERT_TRUE((*currentGrid)[3][5]);
  ASSERT_FALSE((*currentGrid)[3][6]);
  ASSERT_FALSE((*currentGrid)[4][4]);
  ASSERT_TRUE((*currentGrid)[4][5]);
  ASSERT_FALSE((*currentGrid)[4][6]);
  ASSERT_FALSE((*currentGrid)[5][4]);
  ASSERT_TRUE((*currentGrid)[5][5]);
  ASSERT_FALSE((*currentGrid)[5][6]);
  // -
  updateState();
  ASSERT_EQ(3, numLivingCells);
  ASSERT_FALSE((*currentGrid)[3][4]);
  ASSERT_FALSE((*currentGrid)[3][5]);
  ASSERT_FALSE((*currentGrid)[3][6]);
  ASSERT_TRUE((*currentGrid)[4][4]);
  ASSERT_TRUE((*currentGrid)[4][5]);
  ASSERT_TRUE((*currentGrid)[4][6]);
  ASSERT_FALSE((*currentGrid)[5][4]);
  ASSERT_FALSE((*currentGrid)[5][5]);
  ASSERT_FALSE((*currentGrid)[5][6]);
}
