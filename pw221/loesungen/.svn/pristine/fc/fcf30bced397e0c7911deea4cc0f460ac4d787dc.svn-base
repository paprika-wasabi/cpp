// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Authors: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//          Claudius Korzen <korzen@cs.uni-freiburg.de>,
//          Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.
//

#include <gtest/gtest.h>
#include "./SetCharBitShifting.h"

// _____________________________________________________________________________
TEST(SetCharBitShiftingTest, constructor) {
  SetCharBitShifting set;
  for (int c = 0; c < 4; c++) {
    ASSERT_FALSE(set.elements_[c]) << "Failed for char: "
      << static_cast<unsigned char>(c) << " dec: "<< c;
  }
  ASSERT_EQ(0, set.size());
}

// _____________________________________________________________________________
TEST(SetCharBitShiftingTest, insertAndEraseAndLookup) {
  SetCharBitShifting set;

  // Test if the set is empty.
  for (int c = 0; c < 256; c++) {
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: "
      << static_cast<unsigned char>(c) << " dec: "<< c;
  }
  ASSERT_EQ(0, set.size());

  // Insert element 'a'.
  set.insert('a');
  ASSERT_TRUE(set.lookup('a'));
  for (int c = 0; c < 256; c++) {
    if (c == 'a') { continue; }
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: "
      << static_cast<unsigned char>(c) << " dec: "<< c;
  }
  ASSERT_EQ(1, set.size());

  // Insert element 'a' again. This should result in no change.
  set.insert('a');
  ASSERT_TRUE(set.lookup('a'));
  for (int c = 0; c < 256; c++) {
    if (c == 'a') { continue; }
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: "
      << static_cast<unsigned char>(c) << " dec: "<< c;
  }
  ASSERT_EQ(1, set.size());

  // Insert element 'b'.
  set.insert('b');
  ASSERT_TRUE(set.lookup('a'));
  ASSERT_TRUE(set.lookup('b'));
  for (int c = 0; c < 256; c++) {
    if (c == 'a') { continue; }
    if (c == 'b') { continue; }
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: "
      << static_cast<unsigned char>(c) << " dec: "<< c;
  }
  ASSERT_EQ(2, set.size());

  // Insert element 'ü' (hex: fc, dec: 252).
  set.insert('\xfc');
  ASSERT_TRUE(set.lookup('a'));
  ASSERT_TRUE(set.lookup('b'));
  ASSERT_TRUE(set.lookup('\xfc'));
  for (int c = 0; c < 256; c++) {
    if (c == 'a') { continue; }
    if (c == 'b') { continue; }
    if (c == 252) { continue; }
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: "
      << static_cast<unsigned char>(c) << " dec: "<< c;
  }
  ASSERT_EQ(3, set.size());

  // Erase element 'a'.
  set.erase('a');
  ASSERT_TRUE(set.lookup('b'));
  ASSERT_TRUE(set.lookup('\xfc'));
  for (int c = 0; c < 256; c++) {
    if (c == 'b') { continue; }
    if (c == 252) { continue; }
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: "
      << static_cast<unsigned char>(c) << " dec: "<< c;
  }
  ASSERT_EQ(2, set.size());

  // Erase element 'a' again. This should result in no change.
  set.erase('a');
  ASSERT_TRUE(set.lookup('b'));
  ASSERT_TRUE(set.lookup('\xfc'));
  for (int c = 0; c < 256; c++) {
    if (c == 'b') { continue; }
    if (c == 252) { continue; }
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: "
      << static_cast<unsigned char>(c) << " dec: "<< c;
  }
  ASSERT_EQ(2, set.size());
}
