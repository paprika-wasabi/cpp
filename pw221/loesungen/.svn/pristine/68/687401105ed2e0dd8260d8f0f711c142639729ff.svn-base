// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Claudius Korzen <korzen@cs.uni-freiburg.de>.
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.
//
#ifndef TERMINALMANAGER_H_
#define TERMINALMANAGER_H_

// Class for the input from the user.
class UserInput {
 public:
  bool isKeyUp();
  bool isKeyDown();
  bool isKeyLeft();
  bool isKeyRight();
  // The code of the key pressed.
  int keycode_;
  // Was the event a mousecklick.
  bool isMouseclick_;
  // If the event was a mousecklick, then the coordinates
  // of the mouseclick are stored here.
  int mouseX_ = -1;
  int mouseY_ = -1;
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

  // Draw a string at the given position
  void drawString(int x, int y, const char* output);

  // Refresh the screen.
  void refresh();

  // Get the dimensions of the screen.
  int numRows() { return numRows_; }
  int numCols() { return numCols_; }

 private:
  // The number of "logical" rows and columns of the screen.
  int numRows_;
  int numCols_;
};

#endif  // TERMINALMANAGER_H_
