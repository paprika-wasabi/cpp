/* Copyright 2022 */
//  Nerdle.cpp
//  Clang
//
//  Created by Paramie Willmann on 20.07.22.
//

// Implementation of Clone Nerdle with cpp.

#include "./Nerdle.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <random>
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
    validEquation_ = getValidEquation();
}

// ____________________________________________________________________________
void Nerdle::play(TerminalManager* tm) {
    drawBoard(tm);
    // tm->drawString(Row_ - 4, (Col_ / 2) - 3, validEquation_.c_str(), 3);
    while (!GameOver_) {
        readInputFromUser(tm);
        handleKeyInput(tm);
        tm->refresh();
        if (GameWin_) {
            tm->drawString(Row_ - 6, (Col_ / 2) - 3, "YOU WIN", 3);
            tm->drawString(Row_ - 5, (Col_ / 2) - 5, "press q to quit", 3);
        }
    }
}

// ____________________________________________________________________________
void Nerdle::drawBoard(TerminalManager* tm) {
    Col_ = tm->numCols();
    Row_ = tm->numRows();
    for (int row = 0; row < Row_; ++row) {
        for (int col = 0; col < Col_; ++col) {
            if (row == 0 || row == Row_ - 1 || col <= 0 || col >= Col_ - 1) {
                tm->drawPixel(row, col, true, 3);
            } else {
                tm->drawPixel(row, col, false, 3);
            }
        }
    }
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
void Nerdle::insert(TerminalManager* tm, const char* draw) {
    tm->deleteCursor(fieldCor_[Y_][X_].first, fieldCor_[Y_][X_].second);
    tm->drawString(fieldCor_[Y_][X_].first, fieldCor_[Y_][X_].second, draw, 2);
    fieldInput_[Y_][X_] = draw;
    tm->refresh();
    if (X_ != 7) {
        X_ = X_ + 1;
    }
}

// ____________________________________________________________________________
void Nerdle::readInputFromUser(TerminalManager* tm) {
    UserInput userInput;
    userInput = (*tm).getUserInput();
    moveCursor(tm, userInput);
    keyInt_ = userInput.keycode_;
}

// ____________________________________________________________________________
void Nerdle::handleKeyInput(TerminalManager* tm) {
    switch (keyInt_) {
        case '0': {
            insert(tm, "0");
            break;
        }
        case '1': {
            insert(tm, "1");
            break;
        }
        case '2': {
            insert(tm, "2");
            break;
        }
        case '3': {
            insert(tm, "3");
            break;
        }
        case '4': {
            insert(tm, "4");
            break;
        }
        case '5': {
            insert(tm, "5");
            break;
        }
        case '6': {
            insert(tm, "6");
            break;
        }
        case '7': {
            insert(tm, "7");
            break;
        }
        case '8': {
            insert(tm, "8");
            break;
        }
        case '9': {
            insert(tm, "9");
            break;
        }
        case '+': {
            insert(tm, "+");
            break;
        }
        case '-': {
            insert(tm, "-");
            break;
        }
        case '*': {
            insert(tm, "*");
            break;
        }
        case '/': {
            insert(tm, "/");
            break;
        }
        case '=': {
            insert(tm, "=");
            break;
        }
        case 'q': {
            GameOver_ = true;
            break;
        }
        case 263: {  // BACKSPACE VALUE
            backSpace(tm);
            break;
        }
        case 10: {  // ENTER VALUE
            updateBoard(tm);
            break;
        }
        default: {
            break;
        }
    }
}

// ____________________________________________________________________________
void Nerdle::backSpace(TerminalManager* tm) {
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
            tm->drawString(x, y, " ", 2);
        }
}

// ____________________________________________________________________________
void Nerdle::updateBoard(TerminalManager* tm) {
    tm->drawString(Row_ - 2, (Col_ / 2) - 3, " ENTER ", 3);
    std::string join = joinString();
    if (join.length() != 8) {
        tm->drawString(Row_ - 2, (Col_ / 2) - 3, "INVALID", 3);
    } else {
        if (ifCompute(join)) {
            compute(join, tm);
            tm->drawString(Row_ - 2, (Col_ / 2) - 3, " VALID ", 3);
            tm->deleteCursor(fieldCor_[Y_][X_].first,
                             fieldCor_[Y_][X_].second);
            X_ = 0;
            if (Y_ < 6) {
                Y_ = Y_ + 1;
            }
            if (Y_ == 6) {
                tm->drawString(Row_ - 2, (Col_ / 2) - 4, " GAME OVER ", 3);
                tm->refresh();
                sleep(5);
                tm->drawString(Row_ - 2, (Col_ / 2) - 7,
                "GAME WILL TERMINATED SOON", 3);
                tm->refresh();
                sleep(5);
                tm->drawString(Row_ - 2, (Col_ / 2) - 7,
                "         GOOD BYE!!      ", 3);
                tm->refresh();
                sleep(3);
                GameOver_ = true;
            }
        } else {
            tm->drawString(Row_ - 2, (Col_ / 2) - 3, "INVALID", 3);
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
            if (operator_[j + 1] == '*') {
                int first = std::stoi(operand_[j + 1]);
                int second = std::stoi(operand_[j + 2]);
                LHS += first * second;
                break;
            }
            if (operator_[j + 1] == '/') {
                int divisor = std::stoi(operand_[j + 2]);
                int temp = LHS % divisor;
                if (temp != 0) {
                    LHS = -1;
                    break;
                }
                if (divisor != 0) {
                    LHS += (std::stoi(operand_[j + 1]) / divisor);
                    break;
                } else {
                    return false;
                }
            }
            LHS += std::stoi(operand_[j + 1]);
        }
        if (operator_[j] == '-') {
            if (operator_[j + 1] == '*') {
                int first = std::stoi(operand_[j + 1]);
                int second = std::stoi(operand_[j + 2]);
                LHS -= first * second;
                break;
            }
            if (operator_[j + 1] == '/') {
                int divisor = std::stoi(operand_[j + 2]);
                int temp = LHS % divisor;
                if (temp != 0) {
                    LHS = -1;
                    break;
                }
                if (divisor != 0) {
                    LHS -= (std::stoi(operand_[j + 1]) / divisor);
                } else {
                    return false;
                }
            }
            LHS -= std::stoi(operand_[j + 1]);
        }
        if (operator_[j] == '*') {
            LHS = LHS * std::stoi(operand_[j + 1]);
        }
        if (operator_[j] == '/') {
            int divisor = std::stoi(operand_[j + 1]);
            int temp = LHS % divisor;
            if (temp != 0) {
                LHS = -1;
                break;
            }
            if (divisor != 0) {
                LHS = LHS / divisor;
            } else {
                return false;
            }
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
std::string Nerdle::joinString() const {
    std::string result;
    for (int start = 0; start < 8; ++start) {
        result = result + fieldInput_[Y_][start];
    }
    return result;
}

// ____________________________________________________________________________
std::string Nerdle::genEquation() {
    genEquation_.clear();
    std::string result;
    std::string validOperaters[4] = {"+", "*", "-", "/"};
    std::string validInteger[10] = {"0", "1", "2", "3", "4",
                                    "5", "6", "7", "8", "9"};
    std::string validIntegerWithoutzero[9] = {"1", "2", "3", "4",
                                    "5", "6", "7", "8", "9"};
    genEquation_.resize(8);
    int equalIndex = 0;
    // Method from StackOverFlow to generate a random number (modern method)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> validEqualRang(4, 6);
    std::uniform_int_distribution<> oneOrTwo(1, 2);
    std::uniform_int_distribution<> zeroOrOne(0, 1);
    std::uniform_int_distribution<> onetoThree(1, 3);
    std::uniform_int_distribution<> zeroTothree(0, 3);
    std::uniform_int_distribution<> zeroTonine(0, 9);
    std::uniform_int_distribution<> zeroToeight(0, 8);
    // ----------------------------------------------------------------------
    equalIndex = validEqualRang(gen);
    genEquation_[equalIndex] = "=";
    switch (equalIndex) {
    case 4: {  // '=' is at index 4 of Equation
        int valid_index = 0;
        valid_index = oneOrTwo(gen);
        // random valid index between 1 or 2; and then random operator;
        genEquation_[valid_index] = validOperaters[zeroTothree(gen)];
        switch (valid_index) {
        case 1: {
            genEquation_[0] = validIntegerWithoutzero[zeroToeight(gen)];
            genEquation_[2] = validIntegerWithoutzero[zeroToeight(gen)];
            genEquation_[3] = validInteger[zeroTonine(gen)];
            genEquation_[5] = validIntegerWithoutzero[zeroToeight(gen)];
            genEquation_[6] = validInteger[zeroTonine(gen)];
            genEquation_[7] = validInteger[zeroTonine(gen)];
            break;
            }
        case 2: {
            genEquation_[0] = validIntegerWithoutzero[zeroToeight(gen)];
            genEquation_[1] = validInteger[zeroTonine(gen)];
            genEquation_[3] = validIntegerWithoutzero[zeroToeight(gen)];
            genEquation_[5] = validIntegerWithoutzero[zeroToeight(gen)];
            genEquation_[6] = validInteger[zeroTonine(gen)];
            genEquation_[7] = validInteger[zeroTonine(gen)];
            break;
            }
        default: {
            break;
            }
        }
        break;
    }
    case 5: {  // '=' is at index 5 of Equation
        // random how many operation will be 1 or 2.
        switch (oneOrTwo(gen)) {
            case 1: {  // case 1 Operater 3 possible index.
                // random valid index between 1 or 3.
                int valid_index;
                valid_index = onetoThree(gen);
                // and then random every operator.
                genEquation_[valid_index] = validOperaters[zeroTothree(gen)];
                switch (valid_index) {
                case 1: {
                    genEquation_[0] = validIntegerWithoutzero[zeroToeight(gen)];
                    genEquation_[2] = validIntegerWithoutzero[zeroToeight(gen)];
                    genEquation_[3] = validInteger[zeroTonine(gen)];
                    genEquation_[4] = validInteger[zeroTonine(gen)];
                    genEquation_[6] = validIntegerWithoutzero[zeroToeight(gen)];
                    genEquation_[7] = validInteger[zeroTonine(gen)];
                    break;
                    }
                case 2: {
                    genEquation_[0] = validIntegerWithoutzero[zeroToeight(gen)];
                    genEquation_[1] = validInteger[zeroTonine(gen)];
                    genEquation_[3] = validIntegerWithoutzero[zeroToeight(gen)];
                    genEquation_[4] = validInteger[zeroTonine(gen)];
                    genEquation_[6] = validIntegerWithoutzero[zeroToeight(gen)];
                    genEquation_[7] = validInteger[zeroTonine(gen)];
                    break;
                    }
                case 3: {
                    genEquation_[0] = validIntegerWithoutzero[zeroToeight(gen)];
                    genEquation_[1] = validInteger[zeroTonine(gen)];
                    genEquation_[2] = validInteger[zeroTonine(gen)];
                    genEquation_[4] = validIntegerWithoutzero[zeroToeight(gen)];
                    genEquation_[6] = validIntegerWithoutzero[zeroToeight(gen)];
                    genEquation_[7] = validInteger[zeroTonine(gen)];
                    break;
                    }
                default: {
                    break;
                    }
                }
                break;
            }
            case 2: {  // case 2 random operator at index 1 and 3.
                // and then random both operators.
                genEquation_[1] = validOperaters[zeroTothree(gen)];
                genEquation_[3] = validOperaters[zeroTothree(gen)];
                // random all valid Int at pos 0, 2, 4, 6, 7
                genEquation_[0] = validIntegerWithoutzero[zeroToeight(gen)];
                genEquation_[2] = validIntegerWithoutzero[zeroToeight(gen)];
                genEquation_[4] = validIntegerWithoutzero[zeroToeight(gen)];
                genEquation_[6] = validIntegerWithoutzero[zeroToeight(gen)];
                genEquation_[7] = validInteger[zeroTonine(gen)];
                break;
            }
            default:
                break;
        }
        break;
    }
    case 6: {  // '=' is at index 6 of Equation
        int pattern = zeroTothree(gen);
        switch (pattern) {
        case 0: {  // | x | y | i | # | a | b | = | 9 |
            genEquation_[0] = validIntegerWithoutzero[zeroToeight(gen)];
            genEquation_[1] = validInteger[zeroTonine(gen)];
            genEquation_[2] = validInteger[zeroTonine(gen)];
            genEquation_[3] = validOperaters[zeroTothree(gen)];
            genEquation_[4] = validIntegerWithoutzero[zeroToeight(gen)];
            genEquation_[5] = validInteger[zeroTonine(gen)];
            genEquation_[7] = validInteger[zeroTonine(gen)];
            break;
            }
        case 1: {  // | x | y | # | i | # | a | = | 9 |
            genEquation_[0] = validIntegerWithoutzero[zeroToeight(gen)];
            genEquation_[1] = validInteger[zeroTonine(gen)];
            // random Op.
            genEquation_[2] = validOperaters[zeroTothree(gen)];
            genEquation_[3] = validIntegerWithoutzero[zeroToeight(gen)];
            // random Op.
            genEquation_[4] = validOperaters[zeroTothree(gen)];
            genEquation_[5] = validIntegerWithoutzero[zeroToeight(gen)];
            // "="
            genEquation_[7] = validInteger[zeroTonine(gen)];
            break;
            }
        case 2: {  // | x | # | i | # | a | b | = | 9 |
            genEquation_[0] = validIntegerWithoutzero[zeroToeight(gen)];
            // random Op.
            genEquation_[1] = validOperaters[zeroTothree(gen)];
            genEquation_[2] = validIntegerWithoutzero[zeroToeight(gen)];
            // random Op.
            genEquation_[3] = validOperaters[zeroTothree(gen)];
            genEquation_[4] = validIntegerWithoutzero[zeroToeight(gen)];
            genEquation_[5] = validInteger[zeroTonine(gen)];
            genEquation_[7] = validInteger[zeroTonine(gen)];
            break;
            break;
            }
        case 3: {  // | x | # | i | a | # | b | = | 9 |
            genEquation_[0] = validIntegerWithoutzero[zeroToeight(gen)];
            // random Op.
            genEquation_[1] = validOperaters[zeroTothree(gen)];
            genEquation_[2] = validIntegerWithoutzero[zeroToeight(gen)];
            genEquation_[3] = validInteger[zeroTonine(gen)];
            // random Op.
            genEquation_[4] = validOperaters[zeroTothree(gen)];
            genEquation_[5] = validIntegerWithoutzero[zeroToeight(gen)];
            genEquation_[7] = validInteger[zeroTonine(gen)];
            break;
            }
        default: {
            break;
            }
        }
        break;
        }
    default: {
        break;
        }
    }
    for (int start = 0; start < 8; ++start) {
            result = result + genEquation_[start];
    }
    return result;
    // there are 4 valid pattern for '=' at index 6.
    // | x | y | i | # | a | b | = | 9 |
    // | x | y | # | i | # | a | = | 9 |
    // | x | # | i | # | a | b | = | 9 |
    // | x | # | i | a | # | b | = | 9 |
}

// ____________________________________________________________________________
std::string Nerdle::getValidEquation() {
    while (true) {
        std::string temp = genEquation();
        if (ifCompute(temp)) {
            return temp;
        }
    }
}

// ____________________________________________________________________________
void Nerdle::compute(std::string input, TerminalManager* tm) {
    int y = Y_;
    int win = 8;
    int scores = 0;
    for (int i = 0; i < static_cast<int>(input.length()); ++i) {
        std::string temp(1, input[i]);
        if (input[i] == validEquation_[i]) {
            tm->drawGreenBox(fieldCor_[y][i].first,
                             fieldCor_[y][i].second, true, temp.c_str());
            scores = scores + 1;
        } else if (validEquation_.find(temp) != std::string::npos) {
            tm->drawPurpleBox(fieldCor_[y][i].first,
                             fieldCor_[y][i].second, true, temp.c_str());
        } else {
            tm->drawBlackBox(fieldCor_[y][i].first,
                             fieldCor_[y][i].second, true, temp.c_str());
        }
    }
    if (scores == win) {
        GameWin_ = true;
    }
}
