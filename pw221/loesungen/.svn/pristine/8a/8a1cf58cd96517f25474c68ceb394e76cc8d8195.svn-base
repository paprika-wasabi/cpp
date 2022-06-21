// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>

#include "./Collatz.h"
#include <cstdio>

// ___________________________________________________________________________
int collatz(int n, int maxIterations, bool verbose) {
  if (n == 0) {
    // Special case that was specified by the exercise sheet
    return 0;
  }

  if (verbose) printf("%d\n", n);
  for (int i = 0; i <= maxIterations; ++i) {
    if (n == 1) {
      if (verbose) printf("We have reached 1 after %d iterations!\n", i);
      return i;
    }
    if (i < maxIterations) {
      if (n % 2 == 1) {
        n = 3 * n + 1;
      } else {
        n = n / 2;
      }
      if (verbose) printf("%d\n", n);
    }
  }
  if (verbose) printf("I gave up after %d iterations\n", maxIterations);
  return -1;
}
