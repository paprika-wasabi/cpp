/* Copyright 2022 */
//  Nerdle.h
//  Clang
//
//  Created by Paramie Willmann on 20.07.22.
//

// Implementation of Clone Nerdle with cpp.

#ifndef NERDLE_H_
#define NERDLE_H_

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
    // Initialize default board.
    void drawBoard(TerminalManager* tm);

    // if the given equation is mathematically correct.
    // then return True.
    bool ifCompute(std::string input);

    // compute the given input according to Nerdle Logic.
    void compute();

    // update state of Board after valid input.
    // todo: function that changes Box's color to
    // purple green or black.
    void updateBoard(TerminalManager* tm);

    // read all input from Users.
    // to do:: add backspace button to delete string
    void readInputFromUser(TerminalManager* tm);

    // move cursor using arrow key.
    void moveCursor(TerminalManager* tm, UserInput userInput);

    // join all string to equation string after enter is pressed.
    // todo:: not sure if its working or not.
    std::string joinString();

    // store dimension of the screen.
    int Col_;
    int Row_;

    // store position of cursor.
    // initialize it at Top-Left of all Box.
    int X_ = 0;
    int Y_ = 0;

    // store coordination to draw the grey box.
    std::vector<std::vector<std::pair<int, int>>> fieldCor_;

    // store input from user as string.
    std::vector<std::vector<std::string>> fieldInput_;

    // check if GameOver.
    bool GameOver_ = false;
};

#endif  // NERDLE_H_
