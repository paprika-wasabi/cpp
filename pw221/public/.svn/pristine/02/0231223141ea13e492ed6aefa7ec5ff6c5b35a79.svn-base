// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <cstdio>

// Check if the given number is prime.
bool checkIfPrime(int n, bool verbose) {
  if (verbose) printf("Checking whether %d is prime ...\n", n);
  if (n == 1) {
    if (verbose) printf("1 is not prime\n");
    return false;
  }
  int i = 2;
  while (i * i <= n) {
    // If i divides n, then n modulo i is 0.
    if (n % i == 0) {
      if (verbose) printf("Found a divisor: %d\n", i);
      return false;
    }
    i++;
  }
  if (verbose) printf("No true divisor found, number is prime\n");
  return true;
}
