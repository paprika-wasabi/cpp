// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <cstdio>

// Main function.
int main(int argc, char** argv) {
  printf("%d\n", argc);
  printf("%s\n", argv[2]);
  return 0;
  int a[5] = { 513, 2, 3, 4, 5 };
  int x = 12;
  int* p = a;
  int** q = &p;
  printf("%d\n", *p);
  printf("%d\n", *(p + 1));
  printf("%d\n", *(p + 2));
  printf("%d\n", *(p + 3));
  printf("%zu\n", (size_t)p);
}
