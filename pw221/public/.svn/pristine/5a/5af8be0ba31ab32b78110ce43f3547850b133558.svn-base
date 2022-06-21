// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>
// Author: Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>
//

#include <utility>
#include "./SomeData.h"

SomeData createSameValues(char value, int count) {
  SomeData data(count);
  for (int i = 0; i < count; ++i) {
    data[i] = value;
  }
  return data;
}

SomeData returnFromReference() {
  SomeData data(1);
  SomeData& ref = data;
  // Return from reference is never a copy elision, and only a move
  // if we explicitly say so.
  return std::move(ref);
}

int main() {
  SomeData data0 = returnFromReference();
  SomeData data = createSameValues('a', 42);
}
