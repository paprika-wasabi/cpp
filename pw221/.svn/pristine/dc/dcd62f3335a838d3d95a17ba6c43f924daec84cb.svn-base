//  Copyright 2022
//  CollatzTest.cpp
//  Clang
//
//  Created by Paramie Willmann on 04.05.22.
//

#include <gtest/gtest.h>
#include "./Collatz.h"

TEST(CollatzTest, collatz) {
    ASSERT_EQ(collatz(15, 100, false), 1);
    ASSERT_EQ(collatz(7, 5, false), -1);
    ASSERT_EQ(collatz(18, 80, false), 1);
    ASSERT_EQ(collatz(100, 7, false), -1);
    ASSERT_EQ(collatz(0, 8, false), 0);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
