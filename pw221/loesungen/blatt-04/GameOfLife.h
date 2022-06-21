// Copyright 2020, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Claudius Korzen <korzen@cs.uni-freiburg.de>.
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

// The grid, alternated used to store the current and previous state.
const int MAX_SIZE = 1000;
extern bool (*previousGrid)[MAX_SIZE][MAX_SIZE];
extern bool (*currentGrid)[MAX_SIZE][MAX_SIZE];

// Last coordinate clicked inside grid.
extern int lastClickedX;
extern int lastClickedY;

// Additional global state
extern bool isRunning;
extern int numSteps;
extern int numLivingCells;

// Initialize the terminal
void initTerminal();

// Initialize the game
void initGame();

// Handle key and mouse presses. Change the new grid.
bool processUserInput(int keycode);

// Calculate the next state and write it into new grid.
void updateState();

// Count the number of alive cells around given coordinates in the old grid.
int numAliveNeighbours(int x, int y);

// Draw the new grid using ncurses.
void showState();

// Additional helper functions not explicitly mentioned in the sheet.
// Returns true if the coordinates (x, y) are inside the grid
bool isLegalPosition(int x, int y);

#endif  // GAMEOFLIFE_H_
