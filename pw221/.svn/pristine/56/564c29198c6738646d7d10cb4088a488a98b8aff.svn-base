/* Copyright 2022 */
//  GameOfLife.h
//  Clang
//
//  Created by Paramie Willmann on 19.05.22.
//

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

// The current state of all "cells". Initialized to all 0 (which is "false" in
// bool).
const int MAX_SIZE = 250;
extern bool cells[MAX_SIZE][MAX_SIZE];
extern bool nextcells[MAX_SIZE][MAX_SIZE];

// Set Pointer to an array.
extern bool (*state)[MAX_SIZE][MAX_SIZE];
extern bool (*next)[MAX_SIZE][MAX_SIZE];

// Current position (determined by last mouse click).
extern int row;
extern int col;

// Current state if game is pauses and count how many steps have passed
// also the current amount of livings.
extern bool stop;
extern int update_steps;
extern int living;

// Initialize the terminal for use with ncurses.
void initTerminal();

// Initialize the game.
void initGame();

// count how many neighbors are alive.
int numAliveNeighbors(int row, int col);

// Compute for updates next state.
void updateState();

// Show currents state.
void showState();

// proces input key from user.
bool processUserInput(int keycode);

// Put a "glider" at the given position.
void putGlider(int row, int col);

// Set the state of the given cell to "alive". If "toggle", invert the state.
void setCell(int row, int col, bool toggle);

#endif  // GAMEOFLIFE_H_
