// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Claudius Korzen <korzen@cs.uni-freiburg.de>.
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

#include <gtest/gtest.h>
#include "./TerminalManager.h"

class GameOfLife {
 public:
  // Play the gameOfLife;
  void play(TerminalManager*);

 private:
  // The grid, alternated used to store the current and previous state.
  static const int MAX_SIZE = 1000;
  bool grid1_[MAX_SIZE][MAX_SIZE] = { 0 };
  bool grid2_[MAX_SIZE][MAX_SIZE] = { 0 };

  // The grid pointers to the old and the new grid.
  bool (*previousGrid_)[MAX_SIZE][MAX_SIZE] = &grid1_;
  bool (*currentGrid_)[MAX_SIZE][MAX_SIZE] = &grid2_;

  // Glider and glider factory.
  int gliderCoords_[5][2] = {
    {0, 2}, {1, 0}, {1, 2}, {2, 1}, {2, 2}
  };

  static const int GLIDER_FACTORY_SIZE = 36;
  int gliderFactoryCoords_[GLIDER_FACTORY_SIZE][2] = {
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

  // Last coordinate clicked inside grid.
  int lastClickedX_ = -1;
  int lastClickedY_ = -1;

  // Additional information for the current state.
  bool isRunning_ = false;
  int numSteps_ = 0;
  int numLivingCells_ = 0;

  // Handle key and mouse presses. Change the new grid.
  bool processUserInput(UserInput input);
  FRIEND_TEST(GameOfLife, processUserInputQuit);
  FRIEND_TEST(GameOfLife, processUserInputSpace);
  FRIEND_TEST(GameOfLife, processUserInputSmallS);
  FRIEND_TEST(GameOfLife, processUserInputSmallG);
  FRIEND_TEST(GameOfLife, processUserInputSmallR);

  // Calculate the next state and write it into new grid.
  void updateState();
  FRIEND_TEST(GameOfLife, updateStateEmptyGrid);
  FRIEND_TEST(GameOfLife, updateStateStaticObject);
  FRIEND_TEST(GameOfLife, updateStateP2Blinker);

  // Count the number of alive cells around given coordinates in the old grid.
  int numAliveNeighbours(int x, int y);
  FRIEND_TEST(GameOfLife, numAliveNeighboursSingle);
  FRIEND_TEST(GameOfLife, numAliveNeighboursMultiple);

  // Draw the new grid using ncurses.
  void showState(TerminalManager*);

  // Returns true if the coordinates (x, y) are inside the grid (additional
  // helper function not explicitly mentioned on the sheet).
  bool isLegalPosition(int x, int y);
  FRIEND_TEST(GameOfLife, isLegalPosition);
};

#endif  // GAMEOFLIFE_H_
