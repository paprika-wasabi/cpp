// Copyright 2022, University of Freiburg
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>

#include <unistd.h>
#include "./GameOfSnake.h"

// ____________________________________________________________________________
GameOfSnake::GameOfSnake(int numRows, int numCols) {
  numRows_ = numRows;
  numCols_ = numCols;
  headRow_ = numRows_ / 2;
  headCol_ = numCols_ / 2;
  dirRow_ = 0;
  dirCol_ = 1;
  speed_ = 10;
}

// ____________________________________________________________________________
void GameOfSnake::play(TerminalManager* terminalManager) {
  drawBorder(terminalManager);
  drawSnake(terminalManager, true);
  (*terminalManager).refresh();

  while (true) {
    for (int i = 0; i < 1000 / speed_; i++) {
      UserInput userInput = (*terminalManager).getUserInput();
      handleKey(userInput);
      usleep(1000);
    }
    drawSnake(terminalManager, false);
    moveSnake();
    drawSnake(terminalManager, true);
    (*terminalManager).refresh();
    if (liesOnBorder(headRow_, headCol_)) {
      usleep(3'000'000);
      return;
    }
  }
}

// ____________________________________________________________________________
void GameOfSnake::drawBorder(TerminalManager* terminalManager) {
  for (int row = 0; row < numRows_; ++row) {
    for (int col = 0; col < numCols_; ++col) {
      (*terminalManager).drawPixel(row, col, liesOnBorder(row, col), true);
    }
  }
}

// ____________________________________________________________________________
void GameOfSnake::drawSnake(TerminalManager* terminalManager, bool show) {
  (*terminalManager).drawPixel(headRow_, headCol_, show, false);
}

// ____________________________________________________________________________
bool GameOfSnake::liesOnBorder(int row, int col) {
  return row == 0 || row == numRows_ - 1 || col == 0 || col == numCols_ - 1;
}

// ____________________________________________________________________________
void GameOfSnake::moveSnake() {
  headRow_ += dirRow_;
  headCol_ += dirCol_;
}

// ____________________________________________________________________________
void GameOfSnake::handleKey(UserInput userInput) {
  if (userInput.isKeyDown()) {
    dirRow_ = 1;
    dirCol_ = 0;
  } else if (userInput.isKeyUp()) {
    dirRow_ = -1;
    dirCol_ = 0;
  } else if (userInput.isKeyLeft()) {
    dirRow_ = 0;
    dirCol_ = -1;
  } else if (userInput.isKeyRight()) {
    dirRow_ = 0;
    dirCol_ = 1;
  }
}
