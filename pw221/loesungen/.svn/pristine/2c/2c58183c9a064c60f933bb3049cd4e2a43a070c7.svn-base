// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Authors: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//          Claudius Korzen <korzen@cs.uni-freiburg.de>,
//          Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.

#ifndef SETCHARBITSHIFTING_H_
#define SETCHARBITSHIFTING_H_

#include <stdint.h>
#include <gtest/gtest.h>

// An implementation of Set<unsigned char> using fancy bit shifting operations.
class SetCharBitShifting {
 public:
  // Creates a new set of type 'unsigned char'.
  SetCharBitShifting() = default;
  FRIEND_TEST(SetCharBitShiftingTest, constructor);

  // Inserts the given element into this set.
  void insert(unsigned char element);

  // Removes the given element from this set.
  void erase(unsigned char element);

  // Checks if the given elements is contained in this set.
  bool lookup(unsigned char element) const;

  size_t size() const;

  FRIEND_TEST(SetCharBitShiftingTest, insertAndEraseAndLookup);

 private:
  // The elements of the set, stored in 32 bytes.
  uint64_t elements_[4] = {};

  // The number of elements in this set.
  size_t size_ = 0;
};

#endif  // SETCHARBITSHIFTING_H_
