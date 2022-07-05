// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Authors: Hannah Bast <bast@cs.uni-freiburg.de>,
//          Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//          Claudius Korzen <korzen@cs.uni-freiburg.de>,
//          Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.

#include "./Set.h"
#include <utility>

// _____________________________________________________________________________
template class Set<int>;

// _____________________________________________________________________________
template<typename T>
Set<T>::~Set() {
  delete[] elements_;
}

// _____________________________________________________________________________
template <typename T>
size_t Set<T>::size() const {
  return size_;
}

// _____________________________________________________________________________
template<typename T>
void Set<T>::insert(const T& element) {
  // Do nothing if the element is already contained in this set.
  if (lookup(element)) {
    return;
  }
  // Create a new array, copy all elements and append the new element.
  T* newelements_ = new T[size_ + 1];
  for (size_t i = 0; i < size_; i++) {
    newelements_[i] = std::move(elements_[i]);
  }
  newelements_[size_] = element;
  size_++;
  delete[] elements_;
  elements_ = newelements_;
}

// _____________________________________________________________________________
template<typename T>
void Set<T>::erase(const T& element) {
  // Do nothing if the element is not contained in this set.
  if (!lookup(element)) {
    return;
  }
  // Create a new array and copy all elements (except the given element).
  T* newelements_ = new T[size_ - 1];
  size_t j = 0;
  for (size_t i = 0; i < size_; i++) {
    // Don't copy the given element.
    if (elements_[i] != element) {
      newelements_[j] = std::move(elements_[i]);
      j++;
    }
  }
  size_--;
  delete[] elements_;
  elements_ = newelements_;
}

// _____________________________________________________________________________
template<typename T>
bool Set<T>::lookup(const T& element) const {
  for (size_t i = 0; i < size_; i++) {
    if (elements_[i] == element) {
      // The element was found.
      return true;
    }
  }
  return false;
}

// =============================================================================
// Set<unsigned char>.

// _____________________________________________________________________________
size_t Set<unsigned char>::size() const {
  return size_;
}

// _____________________________________________________________________________
void Set<unsigned char>::insert(unsigned char element) {
  if (lookup(element)) { return; }
  elements_[element] = true;
  size_++;
}

// _____________________________________________________________________________
void Set<unsigned char>::erase(unsigned char element) {
  if (!lookup(element)) { return; }
  elements_[element] = false;
  size_--;
}

// _____________________________________________________________________________
bool Set<unsigned char>::lookup(unsigned char element) const {
  return elements_[element];
}
