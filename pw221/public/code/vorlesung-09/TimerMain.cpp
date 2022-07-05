// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include "./Timer.h"
#include <unistd.h>
#include <iostream>

// Try the timer class.
int main() {
  Timer timer;
  usleep(733'000);
  std::cout << timer << std::endl;
  // std::cout << timer.msecPassed() << " ms" << std::endl;
  usleep(267'000);
  std::cout << timer << std::endl;
  // std::cout << timer.msecPassed() << " ms" << std::endl;
}
