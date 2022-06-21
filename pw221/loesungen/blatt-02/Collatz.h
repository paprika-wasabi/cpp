// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>

#ifndef COLLATZ_H_
#define COLLATZ_H_
// Return the number of iterations until 1 is reached. If the input is 1, this
// is 0. If 1 is not reached after maxIterations, return -1.
int collatz(int n, int maxIterations, bool verbose);

#endif  // COLLATZ_H_
