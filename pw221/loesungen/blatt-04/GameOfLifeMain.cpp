// Copyright 2020, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Claudius Korzen <korzen@cs.uni-freiburg.de>.
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.

#include <ncurses.h>
#include <unistd.h>
#include "./GameOfLife.h"

int main() {
  // Initialize terminal and grid.
  initTerminal();
  initGame();

  while (processUserInput(getch())) {
    if (isRunning) {
      updateState();
    }
    // Draw and wait.
    showState();
    usleep(50 * 1000);
  }
  // Clean up window.
  endwin();
}
