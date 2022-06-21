// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>

#include <gtest/gtest.h>
#include "./Collatz.h"

// _____________________________________________________________________________
TEST(CollatzTest, collatz) {
  ASSERT_EQ(collatz(0, 3, false), 0);
  ASSERT_EQ(collatz(1, 3, false), 0);
  ASSERT_EQ(collatz(2, 3, false), 1);
  ASSERT_EQ(collatz(4, 3, false), 2);
  ASSERT_EQ(collatz(8, 3, false), 3);
  ASSERT_EQ(collatz(8, 2, false), -1);
}

// ____________________________________________________________________________
int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
