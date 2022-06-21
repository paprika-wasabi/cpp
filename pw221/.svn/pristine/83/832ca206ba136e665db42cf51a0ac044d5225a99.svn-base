/* Copyright 2022 */
//  GameOfLifeMain.cpp
//  Clang
//
//  Created by Paramie Willmann on 19.05.22.
//

#include <ncurses.h>
#include <unistd.h>
#include "./GameOfLife.h"

// Main function.
int main() {
    initTerminal();
    initGame();
    while (true) {
        int key = getch();
        if (processUserInput(key)) break;
        if (stop == true) {
            continue;
        } else {
            updateState();
            showState();
        }
        usleep(50000);
    }
    endwin();
}
