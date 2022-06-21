// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>
// Author: Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>

#include "./SomeData.h"

// ___________________________________________________________
SomeData::SomeData(size_t n) {
  objectId_ = ++numObjects_;
  printf("Constructor called for #%zu ...\n", objectId_);
  if (n != 0) {
    data_ = new char[n];
  }
  size_ = n;
}

// __________________________________________________________
SomeData::SomeData(const SomeData& other) {
  objectId_ = ++numObjects_;
  printf("COPY constructor called for #%zu ...\n", objectId_);
  size_ = other.size_;
  data_ = new char[size_];
  for (size_t i = 0; i < size_; ++i) { data_[i] = other.data_[i]; }
}

// __________________________________________________________
SomeData::SomeData(SomeData&& other) {
  objectId_ = ++numObjects_;
  printf("MOVE constructor called for #%zu ...\n", objectId_);
  size_ = other.size_;
  data_ = other.data_;

  other.size_ = 0;
  other.data_ = nullptr;
}

// ____________________________________________________________
SomeData& SomeData::operator=(const SomeData& other) {
  if (this == &other) {
    return *this;
  }
  printf("COPY assignment operator called for #%zu ...\n", objectId_);
  delete[] data_;
  size_ = other.size_;
  data_ = new char[size_];
  for (size_t i = 0; i < size_; ++i) { data_[i] = other.data_[i]; }
  return *this;
}

// ______________________________________________________________
SomeData& SomeData::operator=(SomeData&& other) {
  if (this == &other) {
    return *this;
  }
  printf("MOVE assignment operator called for #%zu ...\n", objectId_);
  delete[] data_;
  size_ = other.size_;
  data_ = other.data_;

  other.size_ = 0;
  other.data_ = nullptr;
  return *this;
}

size_t SomeData::numObjects_ = 0;
