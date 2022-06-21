// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>
// Author: Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>

#ifndef SOMEDATA_H_
#define SOMEDATA_H_

#include <cstdlib>
#include <cstdio>

// Class for objects that hold some data (we don't care what exactly), for
// demonstration purposes in lecture V6.
class SomeData {
 private:
  // Initialize to address 0, which is standard for a pointer that points to
  // nothing meaningful yet (address 0 is never a valid address for any
  // program).
  char* data_ = nullptr;
  // The number of bytes. Note that size_t is like unsigned int, but of the
  // right "size" for the given machine (8 bytes for a 64-bit machine).
  size_t size_ = 0;

  // Counter for the number of objects created for this class.
  static size_t numObjects_;
  // A unique ID for each object.
  size_t objectId_ = 0;

 public:
  // Construct object with given number of bytes.
  explicit SomeData(size_t n);

  // Copy constructor: copies the data from the given object into this object
  // (that did not exist so far).
  SomeData(const SomeData& other);

  // Copy assignment operator: copies the data from the given object (that
  // already existed).
  SomeData& operator=(const SomeData& other);

  // Move constructor: moves the data from other into the new object.
  // Other will be empty after this operation.
  SomeData(SomeData&& other);

  // Move assignment operator: moves the data from other.
  // Other will be empty after this operation.
  SomeData& operator=(SomeData&& other);

  // Return the number of bytes.
  size_t size() const {
    return size_;
  }

  // Destructor: frees any memory that has been allocated with new before and
  // not yet freed.
  ~SomeData() {
    printf("Destructor called for object #%zu ...\n", objectId_);
    delete[] data_;
  }

  // Access operators
  char& operator[](size_t i) { return data_[i];}
  const char& operator[](size_t i) const { return data_[i];}
};

#endif  // SOMEDATA_H_

