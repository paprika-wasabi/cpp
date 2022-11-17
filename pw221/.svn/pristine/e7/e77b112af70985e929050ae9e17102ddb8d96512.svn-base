// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Claudius Korzen <korzen@cs.uni-freiburg.de>.
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.
//
// Modified by: Paramie Willmann.
// Modified Purpose: to make it compactible with Nerdle.
// what's new: drawCursor(), deleteCursor(), drawGrayBox().

#include "./NcursesTerminalManager.h"
#include <ncurses.h>
#include <algorithm>
#include <cmath>
#include <stdexcept>

static constexpr size_t systemColors = 16;

// ____________________________________________________________________________
bool UserInput::isKeyUp() { return keycode_ == KEY_UP; }
bool UserInput::isKeyDown() { return keycode_ == KEY_DOWN; }
bool UserInput::isKeyLeft() { return keycode_ == KEY_LEFT; }
bool UserInput::isKeyRight() { return keycode_ == KEY_RIGHT; }

// _____________________________________________________________
size_t NcursesTerminalManager::convertIntensityToColor(float intensity) const {
  intensity = 1 - std::exp(-50.0 * intensity);
  int color = (COLORS - 1 - systemColors) * std::clamp(intensity, 0.0f, 1.0f)
                                          + systemColors;
  return color;
}

// ____________________________________________________________________________
NcursesTerminalManager::NcursesTerminalManager() {
  initscr();
  start_color();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  // Catch mouse events
  mousemask(ALL_MOUSE_EVENTS, NULL);
  mouseinterval(0);
  start_color();

  if (COLORS < 200) {
    endwin();
    throw std::runtime_error{"The TerminalManager requires a terminal with"
      " at least 200 colors. Consider setting `TERM=xterm-256color` before"
      " starting the application"};
  }
  // Define as many shades of a certain color (red in this case) as there are
  // colors.
  // for (int color = systemColors; color < COLORS; ++color) {
  //   int max = 800;
  //   int intensity = max * color / (COLORS - systemColors);
  //   init_color(color, intensity, 0, 0);
  //   // init_color(color, intensity, 0, 0);
  //   init_pair(color, color, 0);
  // }
  // redifine Definition for yellow to grey.
  init_color(COLOR_YELLOW, 500, 500, 500);
  // Init pair of color.
  init_pair(1, COLOR_CYAN, COLOR_WHITE);
  init_pair(2, COLOR_YELLOW, COLOR_WHITE);
  init_pair(3, COLOR_BLACK, COLOR_WHITE);
  init_pair(4, COLOR_GREEN, COLOR_WHITE);
  init_pair(5, COLOR_RED, COLOR_YELLOW);
  numRows_ = LINES;
  numCols_ = COLS / 2;
}

// ____________________________________________________________________________
NcursesTerminalManager::~NcursesTerminalManager() { endwin();}

// ____________________________________________________________________________
void NcursesTerminalManager::drawPixel(int row, int col,
                                bool inverse, int color) {
  if (inverse) attron(A_REVERSE);
  attron(COLOR_PAIR(color));
  mvprintw(row, 2 * col, "  ");
  attroff(COLOR_PAIR(color));
  if (inverse) attroff(A_REVERSE);
}

// ____________________________________________________________________________
void NcursesTerminalManager::refresh() {
  ::refresh();
}

// ___________________________________________________________________________
void NcursesTerminalManager::drawString(int row, int col, const char* output,
                                 int color) {
  attron(COLOR_PAIR(color));
  mvaddstr(row, 2 * col, output);
  attroff(COLOR_PAIR(color));
}

// ___________________________________________________________________________
UserInput NcursesTerminalManager::getUserInput() {
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

// ___________________________________________________________________________
int NcursesTerminalManager::numColors() {
  return COLORS;
}

// ____________________________________________________________________________
void NcursesTerminalManager::drawGrayBox(int row, int col, bool draw) {
  int boxRowRel[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
  int boxColRel[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
  attron(COLOR_PAIR(2));
  if (draw) attron(A_REVERSE);
  for (int i = 0; i < 8; ++i) {
    mvprintw(row + boxRowRel[i], 2 * (col + boxColRel[i]), "  ");
  }
  mvprintw(row, 2 * col, "  ");
  if (draw) attron(A_REVERSE);
  attroff(COLOR_PAIR(2));
  refresh();
}

// ____________________________________________________________________________
void NcursesTerminalManager::drawCursor(int row, int col) {
  int boxRowRel[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
  int boxColRel[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
  attron(COLOR_BLACK);
  for (int i = 0; i < 8; ++i) {
    mvprintw(row + (2 * boxRowRel[i]), 2 * (col + (2 * boxColRel[i])), "**");
  }
  attroff(COLOR_BLACK);
  refresh();
}

// ____________________________________________________________________________
void NcursesTerminalManager::deleteCursor(int row, int col) {
  int boxRowRel[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
  int boxColRel[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
  // attron(COLOR_WHITE);
  for (int i = 0; i < 8; ++i) {
    mvprintw(row + (2 * boxRowRel[i]), 2 * (col + (2 * boxColRel[i])), "  ");
  }
  // attroff(COLOR_WHITE);
  refresh();
}

// ____________________________________________________________________________
void NcursesTerminalManager::deleteChar(int row, int col) {
  // attron(COLOR_YELLOW);
  mvprintw(row, col, "  ");
  // attroff(COLOR_YELLOW);
  refresh();
}
