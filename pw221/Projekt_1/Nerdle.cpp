/* Copyright 2022 */
//  Nerdle.cpp
//  Clang
//
//  Created by Paramie Willmann on 20.07.22.
//

// Implementation of Clone Nerdle with cpp.

#include "./Nerdle.h"
#include <unistd.h>
#include <vector>
#include <string>
#include <utility>
#include "./TerminalManager.h"

// ____________________________________________________________________________
Nerdle::Nerdle() {
    fieldCor_.resize(6);
    for (std::vector<std::pair<int, int>>& rowCor : fieldCor_) {
        rowCor.resize(8);
    }
    fieldInput_.resize(6);
    for (std::vector<std::string>& rowInput : fieldInput_) {
        rowInput.resize(8);
    }
    printf("")
    // to do: gernerate random equation hold up to 8 char.
}

// ____________________________________________________________________________
void Nerdle::play(TerminalManager* tm) {
    drawBoard(tm);
    while (!GameOver_) {
        readInputFromUser(tm);
        tm->refresh();
    }
}

// ____________________________________________________________________________
void Nerdle::drawBoard(TerminalManager* tm) {
    Col_ = tm->numCols();
    Row_ = tm->numRows();
    for (int row = 0; row < Row_; ++row) {
        for (int col = 0; col < Col_; ++col) {
            if (row == 0 || row == Row_ - 1 || col <= 0 || col >= Col_ - 1) {
                tm->drawPixel(row, col, true, 1);
            } else {
                tm->drawPixel(row, col, false, 1);
            }
        }
    }
    // each box need 4 x 4 to compute if we need 8 boxes,
    // then 4 * 8 is size of for loop.
    for (int RowStart = 4, rowGrid = 0; rowGrid < 6;
             RowStart = RowStart + 4, ++rowGrid) {
        for (int ColStart = (Col_ / 2) - 16, colGrid = 0; colGrid < 8;
                 ColStart = ColStart + 4, ++colGrid) {
            tm->drawGrayBox(RowStart, ColStart, true);
            fieldCor_[rowGrid][colGrid] = std::make_pair(RowStart, ColStart);
        }
    }
    tm->refresh();
}

// ____________________________________________________________________________
void Nerdle::readInputFromUser(TerminalManager* tm) {
    UserInput userInput;
    userInput = (*tm).getUserInput();
    moveCursor(tm, userInput);
    switch (userInput.keycode_) {
        case '0': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "0", 2);
            fieldInput_[Y_][X_] = "0";
            tm->refresh();
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            break;
        }
        case '1': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "1", 2);
            fieldInput_[Y_][X_] = "1";
            tm->refresh();
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            break;
        }
        case '2': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "2", 2);
            fieldInput_[Y_][X_] = "2";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case '3': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "3", 2);
            fieldInput_[Y_][X_] = "3";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case '4': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "4", 2);
            fieldInput_[Y_][X_] = "4";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case '5': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "5", 2);
            fieldInput_[Y_][X_] = "5";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case '6': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "6", 2);
            fieldInput_[Y_][X_] = "6";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case '7': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "7", 2);
            fieldInput_[Y_][X_] = "7";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case '8': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "9", 2);
            fieldInput_[Y_][X_] = "8";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case '9': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "9", 2);
            fieldInput_[Y_][X_] = "9";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case '+': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "+", 2);
            fieldInput_[Y_][X_] = "+";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case '-': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "-", 2);
            fieldInput_[Y_][X_] = "-";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case '*': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "*", 2);
            fieldInput_[Y_][X_] = "*";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case '/': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "/", 2);
            fieldInput_[Y_][X_] = "/";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case '=': {
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, "=", 2);
            fieldInput_[Y_][X_] = "=";
            if (X_ != 7) {
                X_ = X_ + 1;
            }
            tm->refresh();
            break;
        }
        case 'q': {
            GameOver_ = true;
            break;
        }
        case 263: {  // BACKSPACE VALUE
            tm->drawString(Row_ - 2, (Col_ / 2) - 3, " BCKSP ", 3);
            int x = fieldCor_[Y_][X_].first;
            int y = fieldCor_[Y_][X_].second;
            if (fieldInput_[Y_][X_] == "") {
                tm->deleteCursor(x, y);
                if (X_ != 0) {
                    X_ = X_ - 1;
                }
            } else {
            fieldInput_[Y_][X_] = "";
            tm->deleteCursor(x, y);
            tm->drawString(fieldCor_[Y_][X_].first,
                           fieldCor_[Y_][X_].second, " ", 2);
            }
            break;
        }
        case 10: {  // ENTER VALUE
            tm->drawString(Row_ - 2, (Col_ / 2) - 3, " ENTER ", 3);
            std::string join = joinString();
            if (join.length() != 8) {
                tm->drawString(Row_ - 5, (Col_ / 2) - 3, "INVALID", 3);
            } else {
                if (ifCompute(join)) {
                    tm->drawString(Row_ - 5, (Col_ / 2) - 3, " VALID ", 3);
                    tm->deleteCursor(fieldCor_[Y_][X_].first,
                                     fieldCor_[Y_][X_].second);
                    X_ = 0;
                    if (Y_ < 5) {
                        Y_ = Y_ + 1;
                    } else {
                        GameOver_ = true;
                    }
                } else {
                    tm->drawString(Row_ - 5, (Col_ / 2) - 3, "INVALID", 3);
                }
            }
            break;
        }
        default: {
            break;
        }
    }
}

// ____________________________________________________________________________
void Nerdle::moveCursor(TerminalManager* tm, UserInput userInput) {
    int x = fieldCor_[Y_][X_].first;
    int y = fieldCor_[Y_][X_].second;
    tm->drawCursor(x, y);
    if (userInput.isKeyRight()) {
        tm->deleteCursor(x, y);
        if (X_ != 7) {
            X_ = X_ + 1;
        }
    }
    if (userInput.isKeyLeft()) {
        tm->deleteCursor(x, y);
        if (X_ > 0) {
            X_ = X_ - 1;
        }
    }
    tm->refresh();
}

// ____________________________________________________________________________
bool Nerdle::ifCompute(std::string input) {
    int k = 0;
    int number_of_operator = 0;
    int lenght = input.length();
    for (int i = 0; i < lenght; ++i) {
        if (input[i] != '+' &&
            input[i] != '-' &&
            input[i] != '*' &&
            input[i] != '/' &&
            input[i] != '=') {
        } else {
            number_of_operator++;
        }
    }
    operand_.resize(number_of_operator + 1);
    operator_.resize(number_of_operator);
    for (int i = 0; i < lenght; ++i) {
        if (input[i] != '+' &&
            input[i] != '-' &&
            input[i] != '*' &&
            input[i] != '/' &&
            input[i] != '=') {
            operand_[k] += input[i];
        } else {
            operator_[k] = input[i];
            k++;
        }
    }
    int j = 0;
    int RHS = std::stoi(operand_[static_cast<int>(operand_.size()) - 1]);
    int LHS = std::stoi(operand_[0]);
    while (operator_[j] != '=') {
        if (operator_[j] == '+') {
            LHS += std::stoi(operand_[j + 1]);
        }
        if (operator_[j] == '-') {
            LHS -= std::stoi(operand_[j + 1]);
        }
        if (operator_[j] == '*') {
            LHS = LHS * std::stoi(operand_[j + 1]);
        }
        if (operator_[j] == '/') {
            LHS = LHS / std::stoi(operand_[j + 1]);
        }
        j++;
    }
    if (LHS == RHS) {
        operand_.clear();
        operator_.clear();
        return true;
    } else {
        operand_.clear();
        operator_.clear();
        return false;
    }
}

// ____________________________________________________________________________
void Nerdle::compute() {
}

// ____________________________________________________________________________
void Nerdle::updateBoard(TerminalManager* tm) {
    tm->drawString(Row_, Col_, "UPDATE", 3);
}

// ____________________________________________________________________________
std::string Nerdle::joinString() {
    std::string result;
    for (int start = 0; start < 8; ++start) {
        result = result + fieldInput_[Y_][start];
    }
    return result;
}
