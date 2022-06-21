// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <cstdlib>
#include <cstdio>

// Class for objects that hold some data (we don't care what exactly), for
// demonstration purposes in lecture V6.
class SomeData {
 public:
  // Construct object with given number of bytes.
  explicit SomeData(size_t n) {
    objectId_ = ++numObjects_;
    printf("Constructor called for #%zu ...\n", objectId_);
    data_ = new char[n];
    size_ = n;
  }

  // Copy constructor: copies the data from the given object into this object
  // (that did not exist so far).
  SomeData(const SomeData& other) {
    objectId_ = ++numObjects_;
    printf("COPY constructor called for #%zu ...\n", objectId_);
    size_ = other.size_;
    data_ = new char[size_];
    for (size_t i = 0; i < size_; ++i) { data_[i] = other.data_[i]; }
  }

  // Copy assignment operator: copies the data from the given object (that
  // already existed).
  SomeData& operator=(const SomeData& other) {
    printf("COPY assignment operator called for #%zu ...\n", objectId_);
    delete[] data_;
    size_ = other.size_;
    data_ = new char[size_];
    for (size_t i = 0; i < size_; ++i) { data_[i] = other.data_[i]; }
    return *this;
  }

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
};

// Static class members must be initialized outside of the class.
size_t SomeData::numObjects_ = 0;


// Main function with some code for demo purposes.
int main() {
  SomeData sd1(100);
  SomeData sd2(sd1);   // Calls the copy constructor.
  SomeData sd3 = sd1;  // Also calls the copy constructor.
  SomeData sd4(42);
  sd4 = sd1;          // This calls the copy assignement operator.
}
