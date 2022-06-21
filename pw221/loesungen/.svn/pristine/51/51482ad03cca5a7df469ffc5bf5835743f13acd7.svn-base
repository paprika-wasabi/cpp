// Copyright 2020, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Claudius Korzen <korzen@cs.uni-freiburg.de>,
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.

#include "./GameOfLife.h"
#include <cstdio>

// ____________________________________________________________________________
bool GameOfLife::processUserInput(UserInput userInput) {
  if (userInput.isMouseclick_) {
    lastClickedX_ = userInput.mouseX_;
    lastClickedY_ = userInput.mouseY_;
    if (isLegalPosition(lastClickedX_, lastClickedY_)) {
      (*currentGrid_)[lastClickedX_][lastClickedY_] =
        !(*currentGrid_)[lastClickedX_][lastClickedY_];
    }
    return true;
  }
  switch (userInput.keycode_) {
    case 'q':
      // Exit
      return false;
    case ' ':
      // Toggle run
      isRunning_ = !isRunning_;
        break;
    case 's':
      // Execute step
      updateState();
      break;
    case 'c':
      // Clear all
      for (int x = 0; x < MAX_SIZE; ++x) {
        for (int y = 0; y < MAX_SIZE; ++y) {
          (*currentGrid_)[x][y] = false;
        }
      }
      break;
    case 'r':
      // Fill randomly
      for (int x = 0; x < MAX_SIZE; ++x) {
        for (int y = 0; y < MAX_SIZE; ++y) {
          (*currentGrid_)[x][y] = drand48() > 0.8;
        }
      }
      break;
    case 'g':
      // Generate glider
      if (isLegalPosition(lastClickedX_, lastClickedY_)) {
        (*currentGrid_)[lastClickedX_][lastClickedY_] = false;
        for (int i = 0; i < 5; ++i) {
          int x = lastClickedX_ + gliderCoords_[i][1];
          int y = lastClickedY_ + gliderCoords_[i][0];
          if (isLegalPosition(x, y)) {
            (*currentGrid_)[x][y] = true;
          }
        }
      }
      break;
    case 'G':
      // Generate glider factory
      if (isLegalPosition(lastClickedX_, lastClickedY_)) {
        (*currentGrid_)[lastClickedX_][lastClickedY_] = false;
        for (int i = 0; i < GLIDER_FACTORY_SIZE; ++i) {
          int x = lastClickedX_ + gliderFactoryCoords_[i][1];
          int y = lastClickedY_ + gliderFactoryCoords_[i][0];
          if (isLegalPosition(x, y)) {
            (*currentGrid_)[x][y] = true;
          }
        }
      }
      break;
  }
  return true;
}

// ____________________________________________________________________________
void GameOfLife::updateState() {
  numLivingCells_ = 0;

  // Exchange the grid pointers without copying the grids.
  bool (*tempGrid)[MAX_SIZE][MAX_SIZE] = currentGrid_;
  currentGrid_ = previousGrid_;
  previousGrid_ = tempGrid;

  for (int x = 0; x < MAX_SIZE; ++x) {
    for (int y = 0; y < MAX_SIZE; ++y) {
      int neighbours = numAliveNeighbours(x, y);
      (*currentGrid_)[x][y] = false;
      if ((*previousGrid_)[x][y]) {
        // Stay alive if 2 or 3 neighbours are alive, die otherwise.
        (*currentGrid_)[x][y] = neighbours > 1 && neighbours < 4;
      } else if (neighbours == 3) {
        // Birth of a cell if exactly 3 neighbours are alive.
        (*currentGrid_)[x][y] = true;
      }
      // Count cells which are alive.
      numLivingCells_ += (*currentGrid_)[x][y];
    }
  }

  // Update the step counter.
  ++numSteps_;
}

// ____________________________________________________________________________
int GameOfLife::numAliveNeighbours(int x, int y) {
  int result = 0;
  // Check the 3x3 around the given cell.
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      // Ignore the given cell itself
      if (dx == 0 && dy == 0) { continue; }
      // Don't check outside the grid, treat them as dead.
      if (isLegalPosition(x + dx, y + dy)) {
        result += (*previousGrid_)[x + dx][y + dy];
      }
    }
  }
  return result;
}

// ____________________________________________________________________________
void GameOfLife::showState(TerminalManager* terminalManager) {
  // Only draw visible cells.
  for (int x = 0; x < MAX_SIZE; ++x) {
    for (int y = 0; y < MAX_SIZE; ++y) {
      (*terminalManager).drawPixel(y, x, (*currentGrid_)[x][y], false);
    }
  }

  char buffer[100];
  snprintf(buffer, sizeof(buffer), "Step: %9d Cells alive: %4d Running: %d",
           numSteps_, numLivingCells_, isRunning_);
  (*terminalManager).drawString(0, 0, buffer);
  (*terminalManager).refresh();
}

// __________________________________________________________________________
bool GameOfLife::isLegalPosition(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < MAX_SIZE) && (y < MAX_SIZE);
}

void GameOfLife::play(TerminalManager* terminalManager) {
  while (processUserInput((*terminalManager).getUserInput())) {
    if (isRunning_) {
      updateState();
    }
    // Draw and wait.
    showState(terminalManager);
    usleep(50 * 1000);
  }
}
