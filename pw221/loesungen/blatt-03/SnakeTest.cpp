// Copyright 2022, University of Freiburg
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>
#include <gtest/gtest.h>
#include <ncurses.h>

#include "./Snake.h"

// NOTE: We can't use "initTerminal" inside the test, so we have to manually
// set numPixelsX and numPixelsY in the test cases.

// ___________________________________________________________________________
TEST(SnakeTest, initSnake) {
  numPixelsX = 100;
  numPixelsY = 100;

  initSnake();
  ASSERT_EQ(posX[12], 1);
  ASSERT_EQ(posX[11], 2);
  ASSERT_EQ(posX[10], 3);
  ASSERT_EQ(posX[9], 4);
  ASSERT_EQ(posX[8], 5);
  ASSERT_EQ(posX[7], 6);
  ASSERT_EQ(posX[6], 7);
  ASSERT_EQ(posX[5], 8);
  ASSERT_EQ(posX[4], 9);
  ASSERT_EQ(posX[3], 10);
  ASSERT_EQ(posX[2], 11);
  ASSERT_EQ(posX[1], 12);
  ASSERT_EQ(posX[0], 13);

  for (int i = 0; i < SNAKE_LENGTH; i++) {
    ASSERT_EQ(posY[i], 50);
  }

  ASSERT_EQ(vx, 1);
  ASSERT_EQ(vy, 0);
}

// ___________________________________________________________________________
TEST(SnakeTest, moveSnake) {
  numPixelsX = 100;
  numPixelsY = 100;

  // Default direction is right
  moveSnake();
  // All y-coordinates are the same, all x-coordinates one more than initially.
  ASSERT_EQ(posX[12], 2);
  ASSERT_EQ(posX[11], 3);
  ASSERT_EQ(posX[10], 4);
  ASSERT_EQ(posX[9], 5);
  ASSERT_EQ(posX[8], 6);
  ASSERT_EQ(posX[7], 7);
  ASSERT_EQ(posX[6], 8);
  ASSERT_EQ(posX[5], 9);
  ASSERT_EQ(posX[4], 10);
  ASSERT_EQ(posX[3], 11);
  ASSERT_EQ(posX[2], 12);
  ASSERT_EQ(posX[1], 13);
  ASSERT_EQ(posX[0], 14);

  for (int i = 0; i < SNAKE_LENGTH; i++) {
    ASSERT_EQ(posY[i], 50);
  }

  // Manually set the direction.
  newVx = 0;
  newVy = 1;
  moveSnake();
  // the head moves y+1, the other elements are shifted.
  //
  ASSERT_EQ(posX[12], 3);
  ASSERT_EQ(posX[11], 4);
  ASSERT_EQ(posX[10], 5);
  ASSERT_EQ(posX[9], 6);
  ASSERT_EQ(posX[8], 7);
  ASSERT_EQ(posX[7], 8);
  ASSERT_EQ(posX[6], 9);
  ASSERT_EQ(posX[5], 10);
  ASSERT_EQ(posX[4], 11);
  ASSERT_EQ(posX[3], 12);
  ASSERT_EQ(posX[2], 13);
  ASSERT_EQ(posX[1], 14);

  ASSERT_EQ(posX[0], 14);
  ASSERT_EQ(posY[0], 51);

  for (int i = 1; i < SNAKE_LENGTH; i++) {
    ASSERT_EQ(posY[i], 50);
  }

  // We could test other values for vx and vy but this is very tedious as long
  // as we have not learned how to "copy" arrays.
}

TEST(SnakeTest, moveSnakeDirectionUpdate) {
  // Initital direction is right.
  initSnake();
  ASSERT_EQ(vx, 1);
  ASSERT_EQ(vy, 0);

  newVx = 1;
  newVy = 0;
  // Still moving right (no change)
  moveSnake();
  ASSERT_EQ(vx, 1);
  ASSERT_EQ(vy, 0);

  // Moving left is not allowed now.
  newVx = -1;
  newVy = 0;
  moveSnake();
  // So we are still moving right
  ASSERT_EQ(vx, 1);
  ASSERT_EQ(vy, 0);

  // Moving down is fine and propagates to vx, vy
  newVx = 0;
  newVy = 1;
  moveSnake();
  ASSERT_EQ(vx, 0);
  ASSERT_EQ(vy, 1);
}

// ___________________________________________________________________________
TEST(SnakeTest, handleKey) {
  initSnake();
  // The snake is moving right because of the default in `initSnake`
  ASSERT_EQ(newVx, 1);
  ASSERT_EQ(newVy, 0);

  // Press KEY_RIGHT, snake is still moving right.
  ASSERT_TRUE(handleKey(KEY_RIGHT));
  ASSERT_EQ(newVx, 1);
  ASSERT_EQ(newVy, 0);

  // Press KEY_LEFT, snake is moving left according to newVx, newVy.
  // (The check is in moveSnake().
  ASSERT_TRUE(handleKey(KEY_LEFT));
  ASSERT_EQ(newVx, -1);
  ASSERT_EQ(newVy, 0);

  // Press KEY_UP
  ASSERT_TRUE(handleKey(KEY_UP));
  ASSERT_EQ(newVx, 0);
  ASSERT_EQ(newVy, -1);

  // Press KEY_LEFT_
  ASSERT_TRUE(handleKey(KEY_LEFT));
  ASSERT_EQ(newVx, -1);
  ASSERT_EQ(newVy, 0);

  // Press KEY_DOWN
  ASSERT_TRUE(handleKey(KEY_DOWN));
  ASSERT_EQ(newVx, 0);
  ASSERT_EQ(newVy, 1);

  // Pressing no key doesn't change anything.
  ASSERT_TRUE(handleKey(-1));
  ASSERT_EQ(newVx, 0);
  ASSERT_EQ(newVy, 1);

  // Pressing any unsupported key doesn't change anything.
  ASSERT_TRUE(handleKey('a'));
  ASSERT_EQ(newVx, 0);
  ASSERT_EQ(newVy, 1);


  // Pressing ESCAPE returns false.
  ASSERT_FALSE(handleKey(27));
}

// ____________________________________________________________________________
TEST(SnakeTest, collidesWithBorder) {
  numPixelsX = 100;
  numPixelsY = 100;

  initSnake();
  ASSERT_EQ(posX[0], 13);
  // The snake is moving right, so after 85 moves we are at pixel 98
  // which is the last legal one (pixels are from 0 to 99, and 99 is
  // the border.
  ASSERT_FALSE(collidesWithBorder());
  for (int i = 0; i < 85; i++) {
    moveSnake();
    ASSERT_FALSE(collidesWithBorder());
  }

  // One more move and we collide.
  moveSnake();
  ASSERT_TRUE(collidesWithBorder());
}

// ___________________________________________________________________________
TEST(SnakeTest, collidesWithSelf) {
  numPixelsX = 100;
  numPixelsY = 100;

  initSnake();
  ASSERT_FALSE(collidesWithSelf());
  // The snake is moving right.
  handleKey(KEY_UP);
  moveSnake();
  ASSERT_FALSE(collidesWithSelf());
  handleKey(KEY_LEFT);
  moveSnake();
  ASSERT_FALSE(collidesWithSelf());
  handleKey(KEY_DOWN);
  moveSnake();
  ASSERT_TRUE(collidesWithSelf());
}

