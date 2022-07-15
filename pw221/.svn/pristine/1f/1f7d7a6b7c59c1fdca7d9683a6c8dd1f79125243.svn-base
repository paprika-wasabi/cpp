/* Copyright 2022 */
//  MockTerminalManager.cpp
//  Clang
//
//  Created by Paramie Willmann on 07.07.22.
//

#include <iostream>
#include <utility>
#include <vector>
#include "./MockTerminalManager.h"

// ____________________________________________________________________________
MockTerminalManager::MockTerminalManager(int Row, int Col) {
    Row_ = Row;
    Col_ = Col;
    // gridIntensity_ = new float[Row_ * Col_];
    // gridBool_ = new bool[Row_ * Col_];
    // using vector from STL.
    // This method provide in Forum exercise 10: init 2D Array.
    fieldBool_.resize(Row_);
    for (std::vector<bool>& rowBool : fieldBool_) {
        rowBool.resize(Col_);
    }
    // using vector from STL.
    // This method provide in Forum exercise 10: init 2D Array.
    fieldFloat_.resize(Row_);
    for (std::vector<float>& rowFloat : fieldFloat_) {
        rowFloat.resize(Col_);
    }
}

// ____________________________________________________________________________
bool MockTerminalManager::isPixelDrawn(int i, int j) {
    // return gridBool_[i * Col_ + j];
    return fieldBool_[i][j];
}

// ____________________________________________________________________________
bool MockTerminalManager::isPixelInverse(int i, int j) {
    // return gridBool_[i * Col_ + j];
    return fieldBool_[i][j];
}

// ____________________________________________________________________________
void MockTerminalManager::drawPixel(int row, int col,
                                    bool inverse, float intensity) {
    // gridIntensity_[row * Col_ + col] = intensity;
    // gridBool_[row * Col_ + col] = inverse;
    fieldFloat_[row][col] = intensity;
    fieldBool_[row][col] = inverse;
}

// ____________________________________________________________________________
float MockTerminalManager::getIntensity(int i, int j) {
    // return gridIntensity_[i * Col_ + j];
    return fieldFloat_[i][j];
}
