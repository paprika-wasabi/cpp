// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include "./Timer.h"
#include <ostream>

// ____________________________________________________________________________
std::ostream& operator<<(std::ostream& os, const Timer& timer) {
  os << timer.msecPassed() << " ms";
  return os;
}
