// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>
// Author: Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>

#include <utility>
#include "./SomeData.h"

// Main function with some code for demo purposes.
int main() {
  SomeData sd1(100);
  sd1 = SomeData(200);

  SomeData sd2(142);
  sd2 = (SomeData&&)sd1;
  // sd1 is now empty/ has been moved from.

  SomeData sd3(std::move(sd2));
  // sd2 is now empty / has been moved from.
}
