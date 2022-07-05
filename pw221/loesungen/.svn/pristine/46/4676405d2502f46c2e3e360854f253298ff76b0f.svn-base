// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Authors: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//          Claudius Korzen <korzen@cs.uni-freiburg.de>,
//          Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>,

#include <stdio.h>
#include "./SetCharBitShifting.h"

// _____________________________________________________________________________
void SetCharBitShifting::insert(unsigned char element) {
  if (lookup(element)) { return; }
  uint index = element / 64;
  uint subindex = element % 64;
  elements_[index] |= (uint64_t(1) << subindex);
  size_++;
}

// _____________________________________________________________________________
void SetCharBitShifting::erase(unsigned char element) {
  if (!lookup(element)) { return; }
  uint index = element / 64;
  uint subindex = element % 64;
  elements_[index] &= ~(uint64_t(1) << subindex);
  size_--;
}

// _____________________________________________________________________________
bool SetCharBitShifting::lookup(unsigned char element) const {
  uint index = element / 64;
  uint subindex = element % 64;
  return elements_[index] & (uint64_t(1) << subindex);
}

// ____________________________________________________________________________
size_t SetCharBitShifting::size() const {
  return size_;
}
