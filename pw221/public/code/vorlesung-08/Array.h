// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.
// Author: Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.

#ifndef ARRAY_H_
#define ARRAY_H_

#include <cstdlib> // For size_t

// A simple array that knows its size. Element type: int.
class ArrayInt {
 private:
  // The elements of the array.
  int* elements_;
  // The number of elements.
  size_t size_;

 public:
  // Create array with given size. All elements will be zero.
  ArrayInt(size_t size);

  // Destructor.
  ~ArrayInt();

  // Get the i-th element as a reference
  const int& operator[](int i) const;
  int& operator[](int i);

  // Get the size of the array.
  size_t size() const;

  // Copy constructor and assignment for the rule of three
  ArrayInt(const ArrayInt& other);
  ArrayInt& operator=(const ArrayInt& other);
};

#endif  // ARRAY_H_
