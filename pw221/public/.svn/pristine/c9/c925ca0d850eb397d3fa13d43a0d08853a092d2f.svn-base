// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <iostream>
#include <vector>
#include <cstdio>
#include <locale>
#include "./Timer.h"
#include "./FunctionArguments.h"

// Define property check as ordinary function.
int isEven(int x) { return x % 2 == 0; }

// Define property check via class.
class IsEven {
 public:
  int operator()(int x) { return x % 2 == 0; }
};

// Perfomance tests of serveral variants to pass a function as an argument.
int main(int argc, char** argv) {
  // Parse the command-line arguments.
  if (argc != 2) {
    std::cout << "Usage: ./FunctionArgumentsMain <size of vector>" << std::endl;
    exit(1);
  }
  size_t n = std::atoi(argv[1]);
  std::cout.imbue(std::locale(""));

  // Create a vector of ints of the given size.
  std::cout << "Creating std::vector with " << n << " elements ..."
            << std::endl;
  std::vector<int> v(n);
  for (size_t i = 0; i < n; ++i) { v[i] = i % 17; }
  std::vector<int> v1 = v;

  {
    std::cout << "Count elements via hard-coded function ... ";
    Timer timer;
    int count = countElementsWithPropertyV0(v1);
    std::cout << "done in " << timer
              << " [count = " << count << "]" << std::endl;
  }

  {
    std::cout << "Count elements via function pointer (C-style) ... ";
    Timer timer;
    int count = countElementsWithPropertyV1(v1, isEven);
    std::cout << "done in " << timer
              << " [count = " << count << "]" << std::endl;
  }

  {
    std::cout << "Count elements via class object (C++-style, old) ... ";
    Timer timer;
    IsEven isEven;
    int count = countElementsWithPropertyV2(v1, isEven);
    std::cout << "done in " << timer
              << " [count = " << count << "]" << std::endl;
  }

  {
    std::cout << "Count elements via class object (C++-style, new) ... ";
    Timer timer;
    int count = countElementsWithPropertyV2(v1,
        [](int x) -> int { return x % 2 == 0; });
    std::cout << "done in " << timer
              << " [count = " << count << "]" << std::endl;
  }
}
