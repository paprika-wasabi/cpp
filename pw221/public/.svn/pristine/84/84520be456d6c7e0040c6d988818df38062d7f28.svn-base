// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>
// Author: Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>
//
//
#include <cstdio>
#include "./SomeData.h"


// Overloading with only different return type does not compile!
// void f() {}
// int f() {return 42;}

void g(int) {}
void g(char) {}

int main() {
  SomeData s1(1);
  SomeData s2(1);
  s1[0] = '1';
  s2[0] = '2';

  const SomeData& cRef = s2;

  s1[0] = cRef[0];

  printf("First char in s1 is %c\n", s1[0]);

  /*
  // Does not work, because left side is a const char&!:w

  cRef[0] = s1[0];
  printf("First char in cRef is %c\n", cRef[0]);
  */

  /*
  // Does not know if g(int) or g(char) should be called (ambiguous)
  double d = 42.0;
  g(d);
  */
}

