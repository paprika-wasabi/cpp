// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <ncurses.h>
#include "./TerminalManager.h"

// ____________________________________________________________________________
bool UserInput::isKeyUp() { return keycode_ == KEY_UP; }
bool UserInput::isKeyDown() { return keycode_ == KEY_DOWN; }
bool UserInput::isKeyLeft() { return keycode_ == KEY_LEFT; }
bool UserInput::isKeyRight() { return keycode_ == KEY_RIGHT; }

// ____________________________________________________________________________
TerminalManager::TerminalManager() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLUE);
  numRows_ = LINES;
  numCols_ = COLS / 2;
}

// ____________________________________________________________________________
TerminalManager::~TerminalManager() {
  endwin();
}

// ____________________________________________________________________________
UserInput TerminalManager::getUserInput() {
  UserInput userInput;
  userInput.keycode_ = getch();
  return userInput;
}

// ____________________________________________________________________________
void TerminalManager::drawPixel(int row, int col,
                                bool inverse, bool useAlternativeColor) {
  if (inverse) attron(A_REVERSE);
  if (useAlternativeColor) attron(COLOR_PAIR(1));
  mvprintw(row, 2 * col, "  ");
  if (useAlternativeColor) attroff(COLOR_PAIR(1));
  if (inverse) attroff(A_REVERSE);
}

// ____________________________________________________________________________
void TerminalManager::refresh() {
  ::refresh();
}
