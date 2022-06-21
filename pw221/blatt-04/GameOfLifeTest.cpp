/* Copyright 2022 */
//  GameOfLifeTest.cpp
//  Clang
//
//  Created by Paramie Willmann on 24.05.22.
//

#include <gtest/gtest.h>
#include "./GameOfLife.h"

TEST(GameOfLifeTest, initGame) {
    initGame();
    EXPECT_TRUE(stop);
}

TEST(GameOfLifeTest, processUserInput) {
    EXPECT_TRUE(processUserInput('q'));
    EXPECT_FALSE(processUserInput('g'));
    stop = true;
    processUserInput(' ');
    EXPECT_FALSE(stop);
    processUserInput(' ');
    EXPECT_TRUE(stop);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
