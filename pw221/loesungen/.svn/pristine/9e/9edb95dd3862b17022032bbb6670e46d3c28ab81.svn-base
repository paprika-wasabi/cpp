// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Authors: Hannah Bast <bast@cs.uni-freiburg.de>,
//          Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//          Claudius Korzen <korzen@cs.uni-freiburg.de>,
//          Johannes Kalmbach<kalmbach@cs.uni-freiburg.de>.

#ifndef SET_H_
#define SET_H_

#include <gtest/gtest.h>

// A simple set to store any number of elements of type T.
template<typename T>
class Set {
 private:
  // Use an variable-length array to store the elements.
  T* elements_ = nullptr;

  // The number of elements in this set.
  size_t size_ = 0;

 public:
  // Creates a new set of an arbitrary type T.
  Set() = default;
  FRIEND_TEST(SetTest, constructor);

  // Destructor.
  ~Set();

  // Inserts the given element into this set.
  void insert(const T& element);

  // Removes the given element from this set.
  void erase(const T& element);

  // Checks if the given elements is contained in this set.
  bool lookup(const T& element) const;

  // Returns the size of the set.
  size_t size() const;

  FRIEND_TEST(SetTest, insertAndEraseAndLookup);
};

// ============================================================================

// A special and more efficient implementation of the Set class for the type
// 'unsigned char'. For simplicity, just implement the set with an fixed-size
// array of length 256 (there are only 256 different chars).
template<>
class Set<unsigned char> {
 private:
  // Use a fixed-size array of length 256 to store the elements.
  bool elements_[256] = {};

  // The number of elements in this set.
  size_t size_ = 0;

 public:
  // Creates a new set of type 'unsigned char'.
  Set() = default;
  FRIEND_TEST(SetCharTest, constructor);

  // Destructor.
  ~Set() = default;

  // Inserts the given element into this set.
  void insert(unsigned char element);

  // Removes the given element from this set.
  void erase(unsigned char element);

  // Checks if the given elements is contained in this set.
  bool lookup(unsigned char element) const;

  // Returns the size of the set.
  size_t size() const;

  FRIEND_TEST(SetCharTest, insertAndEraseAndLookup);
};

#endif  // SET_H_
