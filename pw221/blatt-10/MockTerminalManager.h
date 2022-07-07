/* Copyright 2022 */
//  MockTerminalManager.h
//  Clang
//
//  Created by Paramie Willmann on 07.07.22.
//

#ifndef MOCKTERMINALMANAGER_H_
#define MOCKTERMINALMANAGER_H_

#include "./TerminalManager.h"

class MockTerminalManager : public TerminalManager {
 public:
    explicit MockTerminalManager(int Row, int Col);
    // Get the dimensions of the screen.
    int numRows() const override { return Row_; }
    int numCols() const override { return Col_; }
    // draw it in field of float and bool instead of screen.
    void drawPixel(int row, int col, bool inverse, float intensity) override;
    // return True if that Pixel has been drawn.
    bool isPixelDrawn(int i, int j);
    // return True if that Pixel has been inverted.
    bool isPixelInverse(int i, int j);
    // return Intensity of that coordinates aka Pixel.
    float getIntensity(int i, int j);
 private:
    int Row_;
    int Col_;
    // Pointer Point to field of float and bool.
    float *gridIntensity_;
    bool *gridBool_;
};

class NcursesTerminalManager : public TerminalManager {
};

#endif  // MOCKTERMINALMANAGER_H_