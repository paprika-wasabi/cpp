// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include "./FunctionArguments.h"

// _____
size_t countElementsWithPropertyV0(const std::vector<int>& v) {
  size_t count = 0;
  for (int x : v) { if (x % 2 == 0) ++count; }
  return count;
}

// _____
size_t countElementsWithPropertyV1(
  const std::vector<int>& v, int (*hasProperty)(int)) {
  size_t count = 0;
  for (int x : v) { if (hasProperty(x)) ++count; }
  return count;
}
