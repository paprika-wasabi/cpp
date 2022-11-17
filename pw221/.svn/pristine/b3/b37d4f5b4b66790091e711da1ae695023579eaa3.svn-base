// Copyright 2022, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Claudius Korzen <korzen@cs.uni-freiburg.de>.
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>.
//
// Modified by: Paramie Willmann.
// Modified Purpose: to make it compactible with Nerdle.
// what's new: drawCursor(), deleteCursor(), drawGrayBox().

#ifndef NCURSESTERMINALMANAGER_H_
#define NCURSESTERMINALMANAGER_H_

#include <cstddef>
#include "./TerminalManager.h"

// A class managing the input and output via the terminal, using ncurses.
class NcursesTerminalManager : public TerminalManager {
 public:
  // Constructor: initialize the terminal for use with ncurses.
  NcursesTerminalManager();

  // Destructor: Clean up the screen.
  ~NcursesTerminalManager();

  // Get input from the user.
  UserInput getUserInput() override;

  // Draw a "pixel" at the given position and with the given pairs.
  void drawPixel(int row, int col, bool inverse, int color) override;

  // Draw a string at the given position and with the given pairs.
  void drawString(int row, int col, const char* output, int color) override;

  // Refresh the screen.
  void refresh() override;

  // Get the dimensions of the screen.
  int numRows() const override { return numRows_; }
  int numCols() const override { return numCols_; }

  // Get the number of colors.
  int numColors();

  // draw a grey box at row and col.
  void drawGrayBox(int row, int col, bool draw) override;

  // draw a cursor at row and col.
  void drawCursor(int row, int col) override;

  // delete a cursor at row and col.
  void deleteCursor(int row, int col) override;

  // delete a character at row and col.
  void deleteChar(int row, int col) override;

  // draw a green box at row and col.
  void drawGreenBox(int row, int col, bool draw, const char* output) override;
  // draw a black box at row and col.
  void drawBlackBox(int row, int col, bool draw, const char* output) override;
  // draw a Purple box at row and col.
  void drawPurpleBox(int row, int col, bool draw, const char* output) override;

 private:
  // The number of "logical" rows and columns of the screen.
  int numRows_;
  int numCols_;

  // Convert an intensity in the range [0.0, 1.0] to the index of the
  // corresponding color
  size_t convertIntensityToColor(float intensity) const;
};

#endif  // NCURSESTERMINALMANAGER_H_
