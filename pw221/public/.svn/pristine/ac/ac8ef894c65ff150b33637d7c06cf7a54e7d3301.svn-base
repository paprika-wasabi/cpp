// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <ncurses.h>
#include "./NcursesDemo.h"

// _________________________________________________________________________
int boxRow;
int boxCol;

// _________________________________________________________________________
void initTerminal() {
  initscr();
  curs_set(false);
  // cbreak();
  nodelay(stdscr, true);
  keypad(stdscr, true);
  start_color();
  noecho();
  init_pair(1, COLOR_BLUE, COLOR_WHITE);
  init_pair(2, COLOR_MAGENTA, COLOR_WHITE);
}

// _________________________________________________________________________
void drawBorder() {
  attron(COLOR_PAIR(1));
  for (int row = 0; row < LINES; ++row) {
    for (int col = 0; col < COLS; ++col) {
      if (row == 0 || row == LINES - 1 || col <= 1 || col >= COLS - 2) {
        attron(A_REVERSE);
        mvprintw(row, col, " ");
        attroff(A_REVERSE);
      } else {
        mvprintw(row, col, " ");
      }
    }
  }
  attroff(COLOR_PAIR(1));
  refresh();
}

// _________________________________________________________________________
void drawBox(bool mode) {
  int boxRowRel[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
  int boxColRel[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
  attron(COLOR_PAIR(2));
  if (mode) attron(A_REVERSE);
  for (int i = 0; i < 8; ++i) {
    mvprintw(boxRow + boxRowRel[i], boxCol + boxColRel[i], " ");
  }
  if (mode) attroff(A_REVERSE);
  attroff(COLOR_PAIR(2));
  refresh();
}
