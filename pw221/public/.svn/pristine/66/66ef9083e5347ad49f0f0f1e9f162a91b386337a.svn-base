// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

// The current state of all "cells". Initialized to all 0 (which is "false" in
// bool).
const int MAX_SIZE = 250;
extern bool cells[MAX_SIZE][MAX_SIZE];

// Current position (determined by last mouse click).
extern int row;
extern int col;

// Initialize the terminal for use with ncurses.
void initTerminal();

// Set the state of the given cell to "alive". If "toggle", invert the state.
void setCell(int row, int col, bool toggle);

// Put a "glider" at the given position.
void putGlider(int row, int col);
//
// Put a "glider factory" at the given position.
void putGliderFactory(int row, int col);

// Show the current state on the screen.
void showState();

#endif  // GAMEOFLIFE_H_
