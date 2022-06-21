/* Copyright 2022 */
//  GameOfLifeTest.cpp
//  Clang
//
//  Created by Paramie Willmann on 27.05.22.
//

#include <gtest/gtest.h>
#include "./GameOfLife.h"

// ____________________________________________________________________________
TEST(GameOfLifeTest, constructor) {
  GameOfLife gameOfLife(250, 250);
  EXPECT_TRUE(gameOfLife.stop_);
  ASSERT_EQ(gameOfLife.row_, 250);
  ASSERT_EQ(gameOfLife.col_, 250);
}
