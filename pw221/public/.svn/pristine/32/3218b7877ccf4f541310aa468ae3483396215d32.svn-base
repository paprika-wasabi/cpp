// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.
//


#include <unistd.h>
#include "./TerminalManager.h"
int main() {
  TerminalManager tm;
  int row = 0;
  for (float f = 0.001; f <= 1.0; f*=1.15) {
    for (int col = 0; col < 20; col ++) {
      tm.drawPixel(row, col, true, f);
    }
    ++row;
  }
  tm.refresh();
  usleep(5'000'000);
}
