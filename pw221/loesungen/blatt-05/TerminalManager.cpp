// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Claudius Korzen <korzen@cs.uni-freiburg.de>.
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.
//
#include "./TerminalManager.h"
#include <ncurses.h>

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
  // Catch mouse events
  mousemask(ALL_MOUSE_EVENTS, NULL);
  mouseinterval(0);
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLUE);
  numRows_ = LINES;
  numCols_ = COLS / 2;
}

// ____________________________________________________________________________
TerminalManager::~TerminalManager() { endwin();}

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

// ___________________________________________________________________________
void TerminalManager::drawString(int x, int y, const char* output) {
  mvaddstr(y, x, output);
}

// ___________________________________________________________________________
UserInput TerminalManager::getUserInput() {
  UserInput userInput;
  userInput.keycode_ = getch();
  userInput.isMouseclick_ = false;
  if (userInput.keycode_ == KEY_MOUSE) {
    MEVENT mouseEvent;
    if (getmouse(&mouseEvent) == OK) {
      if (mouseEvent.bstate & BUTTON1_PRESSED) {
        userInput.isMouseclick_ = true;
        userInput.mouseX_ = mouseEvent.x / 2;
        userInput.mouseY_ = mouseEvent.y;
      }
    }
  }
  return userInput;
}
