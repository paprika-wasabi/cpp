// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <cstddef>
#include <vector>

// Property hard-coded.
size_t countElementsWithPropertyV0(const std::vector<int>& v);

// C-Style using function pointer.
size_t countElementsWithPropertyV1(
    const std::vector<int>& v, int (*hasProperty)(int));

// Count the number of elements with the given property.
template <typename HasProperty>
size_t countElementsWithPropertyV2(
    const std::vector<int>& v, HasProperty hasProperty) {
  size_t count = 0;
  for (int x : v) { if (hasProperty(x)) ++count; }
  return count;
}

