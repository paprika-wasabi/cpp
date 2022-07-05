// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.
// Author: Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.

#include <gtest/gtest.h>
#include <cstdint>
#include "./Array.h"

// Generic test function for the Array template class
template <typename T>
void testArray(T testValue) {
  Array<T> array(25);
  for (size_t i = 0; i < array.size(); ++i) {
    // T() is a default constructed T.
    ASSERT_EQ(T(), array[i]);
  }
  array[12] = testValue;

  ASSERT_EQ(testValue, array[12]);
  for (size_t i = 0; i < array.size(); ++i) {
    if (i != 12) {
      ASSERT_EQ(T(), array[i]);
    }
  }
}



TEST(Array, ArrayTemplateInt) {
  testArray<int>(42);
  // For functions the template parameter can be deduced.
  // The following call is equivalent:
  testArray(42);
}

TEST(Array, ArrayInt) {
  ArrayInt array(25);
  for (size_t i = 0; i < array.size(); ++i) {
    ASSERT_EQ(0, array[i]);
  }
  array[12] = 42;

  ASSERT_EQ(42, array[12]);
  for (size_t i = 0; i < array.size(); ++i) {
    if (i != 12) {
      ASSERT_EQ(0, array[i]);
    }
  }

  // Copy constructor is deleted, so this would not compile
  // ArrayInt array2(array);
}

TEST(Array, ArrayFloat) {
  ArrayFloat array(25);
  for (size_t i = 0; i < array.size(); ++i) {
    ASSERT_EQ(0, array[i]);
  }
  array[12] = 42.123f;

  ASSERT_EQ(42.123f, array[12]);
  for (size_t i = 0; i < array.size(); ++i) {
    if (i != 12) {
      ASSERT_EQ(0, array[i]);
    }
  }

  // Copy constructor is deleted, so this would not compile
  // ArrayFloat array2(array);
}

TEST(Array, ArrayBool) {
  Array<bool> array(200);
  for (size_t i = 0; i < array.size(); ++i) {
    ASSERT_FALSE(array.get(i));
  }

  array.set(42, true);
  array.set(128, true);

  ASSERT_TRUE(array.get(42));
  ASSERT_TRUE(array.get(128));

  for (size_t i = 0; i < array.size(); ++i) {
    if (i != 42 && i != 128) {
    ASSERT_FALSE(array.get(i));
    }
  }
}
