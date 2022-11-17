/* Copyright 2022 */
//  MockTerminalManager.h
//  Clang
//
//  Created by Paramie Willmann on 07.07.22.
//  Last Modified by Paramie Willmann on 27.07.22

#ifndef MOCKTERMINALMANAGER_H_
#define MOCKTERMINALMANAGER_H_

#include <vector>
#include <string>
#include "./TerminalManager.h"

class MockTerminalManager : public TerminalManager {
 public:
    explicit MockTerminalManager(int Row, int Col);

    // Get input from the user.
    UserInput getUserInput() override;
    // draw it in field of float and bool instead of screen.
    void drawPixel(int row, int col, bool inverse, int color) override;
    void drawString(int row, int col,
                            const char* output, int color) override;
    void drawGrayBox(int row, int col, bool draw) override;
    void drawGreenBox(int row, int col, bool draw,
                              const char* output) override;
    void drawBlackBox(int row, int col, bool draw,
                              const char* output) override;
    void drawPurpleBox(int row, int col, bool draw,
                               const char* output) override;
    void drawCursor(int row, int col) override;
    void deleteCursor(int row, int col) override;
    void deleteChar(int row, int col) override;
    // Get the dimensions of the screen.
    int numRows() const override { return Row_; }
    int numCols() const override { return Col_; }
    // return True if that Pixel has been drawn.
    bool isPixelDrawn(int i, int j);

    // return True if the Box is grey by default.
    // color pair(2).
    bool isThisBoxGrey(int i, int j);

    // return True if the Box marked as correct and set green.
    // color pair(4).
    bool isThisBoxGreen(int i, int j);

    // return True if the Box is not related correct and set black.
    // color pair(3).
    bool isThisBoxBlack(int i, int j);

    // return True if the Box related and set purple.
    // color pair(6).
    bool isThisBoxPurple(int i, int j);

    // act like a keyboard botton but not one.
    int mockReadKeyInput(int inputChar) {
        keyCode_ = inputChar; return keyCode_;
    }

    // do nothing but wait, MTM do not need to actually refresh.
    void refresh() override;

 private:
    int keyCode_;
    int Row_;
    int Col_;
    std::vector<std::vector<bool>> isPixelDraw_;
    std::vector<std::vector<bool>> isBoxGrey_;
    std::vector<std::vector<bool>> isBoxGreen_;
    std::vector<std::vector<bool>> isBoxBlack_;
    std::vector<std::vector<bool>> isBoxPurple_;

    std::vector<std::vector<std::string>> ThisBoxHaveChar_;
    std::vector<std::vector<int>> ThisBoxColorChar_;
    std::vector<std::vector<bool>> isCursorDraw_;
    std::vector<std::vector<int>> pixelColor_;
};

#endif  // MOCKTERMINALMANAGER_H_
