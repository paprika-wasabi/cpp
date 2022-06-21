// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include "./GameOfLife.h"
#include <ncurses.h>

// ___________________________________________________________________________
bool cells[MAX_SIZE][MAX_SIZE] = {{ 0 }};

// ___________________________________________________________________________
int row;
int col;

// ___________________________________________________________________________
void initTerminal() {
  initscr();              // Initializiation.
  cbreak();               // Don't wait for RETURN.
  noecho();               // Don't echo key presses on screen.
  curs_set(false);        // Don't show the cursor.
  nodelay(stdscr, true);  // Don't wait until key pressed.
  keypad(stdscr, true);   // For KEY_LEFT, KEY_UP, etc.

  mousemask(ALL_MOUSE_EVENTS, NULL);
  mouseinterval(0);
}

// ___________________________________________________________________________
void setCell(int row, int col, bool toggle) {
  if (row >= 0 && row < MAX_SIZE && col >= 0 && col < MAX_SIZE) {
    cells[row][col] = toggle ? !cells[row][col] : true;
  }
}

// ___________________________________________________________________________
void putGlider(int row, int col) {
  int GLIDER_SIZE = 5;
  int gliderCoords[GLIDER_SIZE][2] = {
    {0, 2}, {1, 0}, {1, 2}, {2, 1}, {2, 2}
  };
  setCell(row, col, false);
  setCell(row, col, true);
  for (int i = 0; i < GLIDER_SIZE; ++i) {
    setCell(row + gliderCoords[i][0], col + gliderCoords[i][1], false);
  }
}

// ___________________________________________________________________________
void putGliderFactory(int row, int col) {
  int GLIDER_FACTORY_SIZE = 36;
  int gliderFactoryCoords[GLIDER_FACTORY_SIZE][2] = {
    {0, 24},
    {1, 22}, {1, 24},
    {2, 12}, {2, 13}, {2, 20}, {2, 21}, {2, 34}, {2, 35},
    {3, 11}, {3, 15}, {3, 20}, {3, 21}, {3, 34}, {3, 35},
    {4, 0}, {4, 1}, {4, 10}, {4, 16}, {4, 20}, {4, 21},
    {5, 0}, {5, 1}, {5, 10}, {5, 14}, {5, 16}, {5, 17}, {5, 22}, {5, 24},
    {6, 10}, {6, 16}, {6, 24},
    {7, 11}, {7, 15},
    {8, 12}, {8, 13}
  };
  setCell(row, col, false);
  setCell(row, col, true);
  for (int i = 0; i < GLIDER_FACTORY_SIZE; ++i) {
    setCell(row + gliderFactoryCoords[i][0],
        col + gliderFactoryCoords[i][1], false);
  }
}

// ___________________________________________________________________________
void showState() {
  for (int row = 0; row < MAX_SIZE; ++row) {
    for (int col = 0; col < MAX_SIZE; ++col) {
      if (cells[row][col]) attron(A_REVERSE);
      mvprintw(row, col * 2, "  ");
      if (cells[row][col]) attroff(A_REVERSE);
    }
  }
  refresh();
}
