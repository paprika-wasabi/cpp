// Copyright 2022, University of Freiburg
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>

#ifndef GAMEOFSNAKE_H_
#define GAMEOFSNAKE_H_

#include <gtest/gtest.h>
#include "./TerminalManager.h"

// Class that realizes a very simple variant of the game of "Snake" (where the
// snake is just a single pixel, the head).
class GameOfSnake {
 public:
  // Initialize the game.
  GameOfSnake(int numRows, int numCols);
  FRIEND_TEST(GameOfSnakeTest, constructor);

  // Play the game.
  void play(TerminalManager* terminalManager);

 private:
  // The number of "logical" rows and columns of the screen.
  int numRows_;
  int numCols_;

  // The current position of the head of the snake.
  int headRow_;
  int headCol_;

  // The current direction (default: to the right).
  int dirRow_;
  int dirCol_;

  // Speed of the snake in pixel per second.
  int speed_;

  // Draw the snake (show == true: draws in black, show == true: draws in
  // white).
  void drawSnake(TerminalManager* terminalManager, bool show);

  // Draw a border around the screen.
  void drawBorder(TerminalManager* terminalManager);

  // Return true iff the given position lies on the border.
  bool liesOnBorder(int row, int col);

  // Move the snake in the current direction.
  void moveSnake();
  FRIEND_TEST(GameOfSnakeTest, moveSnake);

  // Update the direction given the last user input.
  void handleKey(UserInput userInput);
};

#endif  // GAMEOFSNAKE_H_
