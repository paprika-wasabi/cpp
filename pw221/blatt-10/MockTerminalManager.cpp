/* Copyright 2022 */
//  MockTerminalManager.cpp
//  Clang
//
//  Created by Paramie Willmann on 07.07.22.
//

#include <iostream>
#include <utility>
#include "./MockTerminalManager.h"

// ____________________________________________________________________________
MockTerminalManager::MockTerminalManager(int Row, int Col) {
    Row_ = Row;
    Col_ = Col;
    gridIntensity_ = new float[Row_ * Col_];
    gridBool_ = new bool[Row_ * Col_];
}

// ____________________________________________________________________________
bool MockTerminalManager::isPixelDrawn(int i, int j) {
    return gridBool_[i * Col_ + j];
}

// ____________________________________________________________________________
bool MockTerminalManager::isPixelInverse(int i, int j) {
    return gridBool_[i * Col_ + j];
}

// ____________________________________________________________________________
void MockTerminalManager::drawPixel(int row, int col, 
                                    bool inverse, float intensity) {
    gridIntensity_[row * Col_ + col] = intensity;
    gridBool_[row * Col_ + col] = inverse;

}

// ____________________________________________________________________________
float MockTerminalManager::getIntensity(int i, int j) {
    return gridIntensity_[i * Col_ + j];
}