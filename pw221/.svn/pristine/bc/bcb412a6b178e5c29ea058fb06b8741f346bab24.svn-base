// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#ifndef TERMINALMANAGER_H_
#define TERMINALMANAGER_H_

// Class for the input from the user.
class UserInput {
 public:
  bool isKeySpace();
  bool isKeyS();
  bool isKeyQ();
  bool isKeyG();
  bool isMouseClick();
  // The code of the key pressed.
  int keycode_;
  // Mouse Position.
  int MouseCol_;
  int MouseRow_;
};

// A class managing the input and output via the terminal, using ncurses.
class TerminalManager {
 public:
  // Constructor: initialize the terminal for use with ncurses.
  TerminalManager();

  // Destructor: Clean up the screen.
  ~TerminalManager();

  // Get input from the user.
  UserInput getUserInput();

  // Draw a "pixel" at the given position.
  void drawPixel(int row, int col, bool inverse, bool useAlternativeColor);

  // Refresh the screen.
  void refresh();

  // write some string.
  void writeStr(bool inverse, int alive);

  // Get the dimensions of the screen.
  int numRows() { return numRows_; }
  int numCols() { return numCols_; }

 private:
  // The number of "logical" rows and columns of the screen.
  int numRows_;
  int numCols_;
};

#endif  // TERMINALMANAGER_H_
