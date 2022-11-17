/* Copyright 2022 */
//  NerdleMain.cpp
//  Clang
//
//  Created by Paramie Willmann on 20.07.22.
//

// DriverCode for Nerdle.

#include "./Nerdle.h"
#include "./NcursesTerminalManager.h"

int main() {
    Nerdle Game;
    NcursesTerminalManager tm;
    Game.play(&tm);
}
