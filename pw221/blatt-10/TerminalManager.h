/* Copyright 2022 */
//  TerminalManager.h
//  Clang
//
//  Created by Paramie Willmann on 18.07.22.
//  Implementation of Parents class for TerminalManager.

#ifndef TERMINALMANAGER_H_
#define TERMINALMANAGER_H_

#include <cstddef>

class TerminalManager {
 public:
    virtual ~TerminalManager() { }
    virtual void drawPixel(int row, int col, bool inverse, float intensity) = 0;
    virtual void refresh() = 0;
    virtual int numRows() const = 0;
    virtual int numCols() const = 0;
};
#endif  // TERMINALMANAGER_H_
