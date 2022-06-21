// Copyright 2020, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Claudius Korzen <korzen@cs.uni-freiburg.de>,
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "./GameOfLife.h"

// The grid, alternated used to store the current and previous state.
bool grid1[MAX_SIZE][MAX_SIZE];
bool grid2[MAX_SIZE][MAX_SIZE];
bool (*previousGrid)[MAX_SIZE][MAX_SIZE];
bool (*currentGrid)[MAX_SIZE][MAX_SIZE];

// Glider.
int glider[5][2] = { {1, 0}, {2, 1}, {0, 2}, {1, 2}, {2, 2} };

// Last click, used to generate glider and cannon.
int lastClickedX;
int lastClickedY;

// Global state
bool isRunning;
int numSteps;
int numLivingCells;

// ____________________________________________________________________________
void initTerminal() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  // Catch mouse events
  mousemask(ALL_MOUSE_EVENTS, NULL);
  mouseinterval(0);
}

// ____________________________________________________________________________
void initGame() {
  for (int x = 0; x < MAX_SIZE; ++x) {
    for (int y = 0; y < MAX_SIZE; ++y) {
      grid1[x][y] = false;
      grid2[x][y] = false;
    }
  }

  previousGrid = &grid1;
  currentGrid = &grid2;

  lastClickedX = -1;
  lastClickedY = -1;

  isRunning = false;
  numSteps = 0;
  numLivingCells = 0;
}

// ____________________________________________________________________________
bool processUserInput(int keycode) {
  MEVENT event;
  switch (keycode) {
    case 'q':
      // Exit
      return false;
    case ' ':
      // Toggle run
      isRunning = !isRunning;
        break;
    case 's':
      // Execute step
      updateState();
      break;
    case 'c':
      // Clear all
      for (int x = 0; x < MAX_SIZE; ++x) {
        for (int y = 0; y < MAX_SIZE; ++y) {
          (*currentGrid)[x][y] = false;
        }
      }
      break;
    case 'r':
      // Fill randomly
      for (int x = 0; x < MAX_SIZE; ++x) {
        for (int y = 0; y < MAX_SIZE; ++y) {
          (*currentGrid)[x][y] = drand48() > 0.8;
        }
      }
      break;
    case 'g':
      // Generate glider
      if (isLegalPosition(lastClickedX, lastClickedY)) {
        (*currentGrid)[lastClickedX][lastClickedY] = false;
        for (int i = 0; i < 5; ++i) {
          int x = lastClickedX + glider[i][0];
          int y = lastClickedY + glider[i][1];
          if (isLegalPosition(x, y)) {
            (*currentGrid)[x][y] = true;
          }
        }
      }
      break;
    case KEY_MOUSE:
      if (getmouse(&event) == OK) {
        if (event.bstate & BUTTON1_PRESSED) {
          // Store position of click and invert cell.
          // Check if the click was inside the grid:
          //
          lastClickedX = event.x / 2;
          lastClickedY = event.y;
          if (isLegalPosition(lastClickedX, lastClickedY)) {
            (*currentGrid)[lastClickedX][lastClickedY] =
              !(*currentGrid)[lastClickedX][lastClickedY];
          }
        }
      }
      break;
  }
  return true;
}

// ____________________________________________________________________________
void updateState() {
  numLivingCells = 0;

  // Exchange the grid pointers without copying the grids.
  bool (*tempGrid)[MAX_SIZE][MAX_SIZE] = currentGrid;
  currentGrid = previousGrid;
  previousGrid = tempGrid;

  for (int x = 0; x < MAX_SIZE; ++x) {
    for (int y = 0; y < MAX_SIZE; ++y) {
      int neighbours = numAliveNeighbours(x, y);
      (*currentGrid)[x][y] = false;
      if ((*previousGrid)[x][y]) {
        // Stay alive if 2 or 3 neighbours are alive, die otherwise.
        (*currentGrid)[x][y] = neighbours > 1 && neighbours < 4;
      } else if (neighbours == 3) {
        // Birth of a cell if exactly 3 neighbours are alive.
        (*currentGrid)[x][y] = true;
      }
      // Count cells which are alive.
      numLivingCells += (*currentGrid)[x][y];
    }
  }


  // Update the step counter.
  ++numSteps;
}

// ____________________________________________________________________________
int numAliveNeighbours(int x, int y) {
  int result = 0;
  // Check the 3x3 around the given cell.
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      // Ignore the given cell itself
      if (dx == 0 && dy == 0) { continue; }
      // Don't check outside the grid, treat them as dead.
      if (isLegalPosition(x + dx, y + dy)) {
        result += (*previousGrid)[x + dx][y + dy];
      }
    }
  }
  return result;
}

// ____________________________________________________________________________
void showState() {
  // Only draw visible cells.
  for (int x = 0; x < MAX_SIZE; ++x) {
    for (int y = 0; y < MAX_SIZE; ++y) {
      attroff(A_REVERSE);
      if ((*currentGrid)[x][y]) {
        attron(A_REVERSE);
      }
      mvprintw(y, x * 2, "  ");
    }
  }
  attroff(A_REVERSE);
  mvprintw(0, 0, "Step: %9d Cells alive: %4d Running: %d", numSteps,
           numLivingCells, isRunning);
}

// __________________________________________________________________________
bool isLegalPosition(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < MAX_SIZE) && (y < MAX_SIZE);
}
