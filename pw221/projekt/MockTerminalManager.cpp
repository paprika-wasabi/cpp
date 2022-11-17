/* Copyright 2022 */
//  MockTerminalManager.cpp
//  Clang
//
//  Created by Paramie Willmann on 27.07.22.
//  MockTerminalManager to intergrated with NerdleTest.cpp

#include <unistd.h>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include "./MockTerminalManager.h"

// ____________________________________________________________________________
MockTerminalManager::MockTerminalManager(int Row, int Col) {
    Row_ = Row;
    Col_ = Col;
    isPixelDraw_.resize(Row_);
    for (std::vector<bool>& rowDraw : isPixelDraw_) {
        rowDraw.resize(Col_);
    }
    pixelColor_.resize(Row_);
    for (std::vector<int>& rowColor : pixelColor_) {
        rowColor.resize(Col_);
    }
    isBoxGrey_.resize(Row_);
    for (std::vector<bool>& rowGrey : isBoxGrey_) {
        rowGrey.resize(Col_);
    }
    isBoxGreen_.resize(Row_);
    for (std::vector<bool>& rowGreen : isBoxGreen_) {
        rowGreen.resize(Col_);
    }
    isBoxBlack_.resize(Row_);
    for (std::vector<bool>& rowBlack : isBoxBlack_) {
        rowBlack.resize(Col_);
    }
    isBoxPurple_.resize(Row_);
    for (std::vector<bool>& rowPurple : isBoxPurple_) {
        rowPurple.resize(Col_);
    }
    ThisBoxHaveChar_.resize(Row_);
    for (std::vector<std::string>& rowHaveChar : ThisBoxHaveChar_) {
        rowHaveChar.resize(Col_);
    }
    ThisBoxColorChar_.resize(Row_);
    for (std::vector<int>& rowCharColor : ThisBoxColorChar_) {
        rowCharColor.resize(Col_);
    }
    isCursorDraw_.resize(Row_);
    for (std::vector<bool>& rowCursor : isCursorDraw_) {
        rowCursor.resize(Col_);
    }
}

// ____________________________________________________________________________
void MockTerminalManager::drawString(int row, int col,
                                     const char* output, int color) {
    ThisBoxHaveChar_[row][col] = output;
    ThisBoxColorChar_[row][col] = color;
}

// ____________________________________________________________________________
void MockTerminalManager::deleteChar(int row, int col) {
    ThisBoxHaveChar_[row][col] = "";
    ThisBoxColorChar_[row][col] = 0;
}

// ____________________________________________________________________________
void MockTerminalManager::drawCursor(int row, int col) {
    isCursorDraw_[row][col] = true;
}

// ____________________________________________________________________________
void MockTerminalManager::deleteCursor(int row, int col) {
    isCursorDraw_[row][col] = false;
}

// ____________________________________________________________________________
void MockTerminalManager::drawGrayBox(int row, int col, bool draw) {
    isBoxGrey_[row][col] = draw;
    isBoxBlack_[row][col] = false;
    isBoxGreen_[row][col] = false;
    isBoxPurple_[row][col] = false;
}

// ____________________________________________________________________________
void MockTerminalManager::drawGreenBox(int row, int col, bool draw,
                                       const char* output) {
    isBoxGrey_[row][col] = false;
    isBoxBlack_[row][col] = false;
    isBoxGreen_[row][col] = draw;
    isBoxPurple_[row][col] = false;
    ThisBoxHaveChar_[row][col] = output;
    ThisBoxColorChar_[row][col] = 4;
}

// ____________________________________________________________________________
void MockTerminalManager::drawBlackBox(int row, int col, bool draw,
                                       const char* output) {
    isBoxGrey_[row][col] = false;
    isBoxBlack_[row][col] = draw;
    isBoxGreen_[row][col] = false;
    isBoxPurple_[row][col] = false;
    ThisBoxHaveChar_[row][col] = output;
    ThisBoxColorChar_[row][col] = 3;
}

// ____________________________________________________________________________
void MockTerminalManager::drawPurpleBox(int row, int col, bool draw,
                                       const char* output) {
    isBoxGrey_[row][col] = false;
    isBoxBlack_[row][col] = false;
    isBoxGreen_[row][col] = false;
    isBoxPurple_[row][col] = draw;
    ThisBoxHaveChar_[row][col] = output;
    ThisBoxColorChar_[row][col] = 6;
}


// ____________________________________________________________________________
void MockTerminalManager::drawPixel(int row, int col,
                                    bool inverse, int color) {
    isPixelDraw_[row][col] = inverse;
    pixelColor_[row][col] = color;
}

// ____________________________________________________________________________
bool MockTerminalManager::isPixelDrawn(int i, int j) {
    return isPixelDraw_[i][j];
}

// ____________________________________________________________________________
bool MockTerminalManager::isThisBoxGrey(int i, int j) {
    return isBoxGrey_[i][j];
}

// ____________________________________________________________________________
bool MockTerminalManager::isThisBoxGreen(int i, int j) {
    return isBoxGreen_[i][j];
}

// ____________________________________________________________________________
bool MockTerminalManager::isThisBoxBlack(int i, int j) {
    return isBoxBlack_[i][j];
}

// ____________________________________________________________________________
bool MockTerminalManager::isThisBoxPurple(int i, int j) {
    return isBoxPurple_[i][j];
}

// ____________________________________________________________________________
UserInput MockTerminalManager::getUserInput() {
    UserInput userInput;
    userInput.keycode_ = keyCode_;
    userInput.isMouseclick_ = false;
    userInput.mouseX_ = -1;
    userInput.mouseY_ = -1;
    return userInput;
}

// ____________________________________________________________________________
void MockTerminalManager::refresh() {
    usleep(1);
}
