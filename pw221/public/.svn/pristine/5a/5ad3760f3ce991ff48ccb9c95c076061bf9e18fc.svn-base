// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <gtest/gtest.h>
#include "./Prime.h"

TEST(PrimeTest, checkIfPrime) {
  ASSERT_EQ(checkIfPrime(1, false), false);
  ASSERT_EQ(checkIfPrime(2, false), true);
  ASSERT_EQ(checkIfPrime(42, false), false);
  ASSERT_EQ(checkIfPrime(101, false), true);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
