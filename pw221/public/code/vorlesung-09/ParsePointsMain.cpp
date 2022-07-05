// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include "./Timer.h"
#include <string>
#include <string_view>
#include <iostream>
#include <fstream>

// Parse tsv file from Ü9 to show some things.
int main(int argc, char** argv) {
  // Parse the command-line arguments.
  if (argc != 2) {
    std::cout << "Usage: ./ParsePointsMain <filename>" << std::endl;
    exit(1);
  }
  std::string filename = argv[1];

  // Read the file line by line.
  std::ifstream file(filename);
  std::string line;
  int numLines = 0;
  int numDigits = 0;
  int numChars = 0;
  std::cout << "Reading points from \"" << filename << "\" ... ";
  Timer timer;
  while (std::getline(file, line)) {
    // Use string view to avoid the copies.
    std::string_view lineView = line;
    // Parse the coordinates and the name from the string.
    size_t pos1 = lineView.find('(');
    size_t pos2 = lineView.find(')', pos1 + 1);
    size_t pos3 = lineView.find('"', pos2 + 1);
    size_t pos4 = lineView.find('"', pos3 + 1);
    std::string_view coordinates = lineView.substr(pos1 + 1, pos2 - pos1 - 1);
    std::string_view name = lineView.substr(pos3 + 1, pos4 - pos3 - 1);
    numDigits += coordinates.size() - 3;
    numChars += name.size();
    numLines++;
  }
  std::cout << "done in " << timer
            << ", avg #digits = " << (numDigits / numLines)
            << ", avg #chars = " << (numChars / numLines)
            << std::endl;
}
