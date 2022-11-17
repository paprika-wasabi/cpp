/* Copyright 2022 */
//  Nerdle.h
//  Clang
//
//  Created by Paramie Willmann on 20.07.22.
//

// Implementation of Clone Nerdle with cpp.

#ifndef NERDLE_H_
#define NERDLE_H_

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <utility>
#include "./TerminalManager.h"

class Nerdle {
 public:
    // Initialize the game by random generates equation.
    Nerdle();
    // Play the game.
    void play(TerminalManager* tm);

 private:
    // get only Valid Equation.
    std::string getValidEquation();

    // Initialize default board.
    void drawBoard(TerminalManager* tm);

    // compute the given valid input according to Nerdle Logic.
    // and update the screen.
    FRIEND_TEST(Nerdle, EvaluationInputWin);
    FRIEND_TEST(Nerdle, EvaluationInput1);
    FRIEND_TEST(Nerdle, EvaluationInput2);
    FRIEND_TEST(Nerdle, EvaluationInputAllBlack);
    void compute(std::string input, TerminalManager* tm);

    // update state of Board after valid input.
    void updateBoard(TerminalManager* tm);

    // read all input from Users.
    FRIEND_TEST(Nerdle, readInputFromUser);
    void readInputFromUser(TerminalManager* tm);

    // handle key input if the key is pressed.
    void handleKeyInput(TerminalManager* tm);

    // move cursor using arrow key.
    void moveCursor(TerminalManager* tm, UserInput userInput);

    // insert a character by users.
    void insert(TerminalManager* tm, const char* draw);

    // when backspace botton was pressed.
    void backSpace(TerminalManager* tm);

    // generate all Equation.
    std::string genEquation();

    // if the given equation is mathematically correct.
    // then return True.
    FRIEND_TEST(Nerdle, ifCompute);
    bool ifCompute(std::string input);

    // join all string to equation string after enter is pressed.
    std::string joinString() const;

    // store dimension of the screen.
    int Col_;
    int Row_;

    // store position of cursor.
    // initialize it at Top-Left of all Box.
    int X_ = 0;
    int Y_ = 0;

    // store which key is pressed as an integer.
    int keyInt_;

    // string class that store a valid Question.
    std::string validEquation_;

    // store coordination to draw the box.
    std::vector<std::vector<std::pair<int, int>>> fieldCor_;

    // store input from user as string.
    std::vector<std::vector<std::string>> fieldInput_;

    // generate all posible random Equation don't care if its valid.
    std::vector<std::string> genEquation_;

    // Temporary Vector to store operand and operator.
    // used with ifCompute() function.
    // will be reset and clear every times.
    std::vector<std::string> operand_;
    std::vector<char> operator_;

    // check if GameOver.
    bool GameOver_ = false;
    bool GameWin_ = false;
};

#endif  // NERDLE_H_
