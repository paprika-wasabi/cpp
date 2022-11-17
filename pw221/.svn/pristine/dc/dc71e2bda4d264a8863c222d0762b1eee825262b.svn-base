/* Copyright 2022 */
//  NerdleTest.cpp
//  Clang
//
//  Created by Paramie Willmann on 27.05.22.
//

#include <gtest/gtest.h>
#include <utility>
#include "./Nerdle.h"
#include "./MockTerminalManager.h"

TEST(Nerdle, readInputFromUser) {
    Nerdle game;
    MockTerminalManager mtm(100, 100);
    // int 48 is char(48) which is '1'.
    mtm.mockReadKeyInput(48);
    game.readInputFromUser(&mtm);
    EXPECT_EQ(48, game.keyInt_);
    // int 49 is char(49) which is '2'.
    mtm.mockReadKeyInput(49);
    game.readInputFromUser(&mtm);
    EXPECT_EQ(49, game.keyInt_);
    // int 50 is char(50) which is '3'.
    mtm.mockReadKeyInput(50);
    game.readInputFromUser(&mtm);
    EXPECT_EQ(50, game.keyInt_);
    // int 51 is char(51) which is '4'.
    mtm.mockReadKeyInput(51);
    game.readInputFromUser(&mtm);
    EXPECT_EQ(51, game.keyInt_);
    // int 113 is char(113) is 'q'.
    mtm.mockReadKeyInput(113);
    game.readInputFromUser(&mtm);
    EXPECT_EQ(113, game.keyInt_);
    // test if "ENTER" is pressed.
    mtm.mockReadKeyInput(10);
    game.readInputFromUser(&mtm);
    EXPECT_EQ(10, game.keyInt_);
}

TEST(Nerdle, ifCompute) {
    Nerdle game;
    EXPECT_TRUE(game.ifCompute("12+34=46"));
    EXPECT_TRUE(game.ifCompute("2+3*6=20"));
    // TEST IF MATHEMATICALLY COMPUTE.
    // EXPECT FALSE.
    EXPECT_FALSE(game.ifCompute("2+3*6=36"));
    // TEST IF MATHEMATICALLY COMPUTE.
    // EXPECT FALSE.
    EXPECT_FALSE(game.ifCompute("2+6/2=4"));
    EXPECT_TRUE(game.ifCompute("2+6/2=5"));
    // TEST IF DIVISIBLE.
    // EXPECT FALSE.
    EXPECT_FALSE(game.ifCompute("5/2*4=10"));
    // TEST IF MATHEMATICALLY COMPUTE.
    // EXPECT TRUE.
    EXPECT_TRUE(game.ifCompute("12-3*4=0"));
}

TEST(Nerdle, EvaluationInputWin) {
    Nerdle game;
    game.validEquation_ = "12-3*4=0";
    MockTerminalManager mtm(100, 100);
    game.drawBoard(&mtm);
    game.compute("12-3*4=0", &mtm);
    for (int i = 0; i < 8; ++i) {
        EXPECT_TRUE(mtm.isThisBoxGreen(game.fieldCor_[0][i].first,
                           game.fieldCor_[0][i].second));
    }
}

TEST(Nerdle, EvaluationInput1) {
    Nerdle game;
    game.validEquation_ = "12-3*4=0";
    MockTerminalManager mtm(100, 100);
    game.drawBoard(&mtm);
    game.compute("12-4*3=0", &mtm);
    // EXPECT SYMBOL G = GREEN P = PURPLE.
    // GGGPGPGG.
    for (int i = 0; i < 3; ++i) {
        EXPECT_TRUE(mtm.isThisBoxGreen(game.fieldCor_[0][i].first,
                           game.fieldCor_[0][i].second));
    }
        EXPECT_TRUE(mtm.isThisBoxPurple(game.fieldCor_[0][3].first,
                           game.fieldCor_[0][3].second));
        EXPECT_TRUE(mtm.isThisBoxGreen(game.fieldCor_[0][4].first,
                           game.fieldCor_[0][4].second));
        EXPECT_TRUE(mtm.isThisBoxPurple(game.fieldCor_[0][5].first,
                           game.fieldCor_[0][5].second));
    for (int i = 6; i < 8; ++i) {
        EXPECT_TRUE(mtm.isThisBoxGreen(game.fieldCor_[0][i].first,
                           game.fieldCor_[0][i].second));
    }
}

TEST(Nerdle, EvaluationInput2) {
    Nerdle game;
    game.validEquation_ = "12-3*4=0";
    MockTerminalManager mtm(100, 100);
    game.drawBoard(&mtm);
    game.compute("17-4*3=5", &mtm);
    // EXPECT SYMBOL G = GREEN P = PURPLE. B = BLACK.
    // GBGPGPGB.
    EXPECT_TRUE(mtm.isThisBoxGreen(game.fieldCor_[0][0].first,
                            game.fieldCor_[0][0].second));
    EXPECT_TRUE(mtm.isThisBoxBlack(game.fieldCor_[0][1].first,
                            game.fieldCor_[0][1].second));
    EXPECT_TRUE(mtm.isThisBoxGreen(game.fieldCor_[0][2].first,
                            game.fieldCor_[0][2].second));
    EXPECT_TRUE(mtm.isThisBoxPurple(game.fieldCor_[0][3].first,
                            game.fieldCor_[0][3].second));
    EXPECT_TRUE(mtm.isThisBoxGreen(game.fieldCor_[0][4].first,
                            game.fieldCor_[0][4].second));
    EXPECT_TRUE(mtm.isThisBoxPurple(game.fieldCor_[0][5].first,
                            game.fieldCor_[0][5].second));
    EXPECT_TRUE(mtm.isThisBoxGreen(game.fieldCor_[0][6].first,
                            game.fieldCor_[0][6].second));
    EXPECT_TRUE(mtm.isThisBoxBlack(game.fieldCor_[0][7].first,
                            game.fieldCor_[0][7].second));
}

TEST(Nerdle, EvaluationInputAllBlack) {
    Nerdle game;
    game.validEquation_ = "12-3*4=0";
    MockTerminalManager mtm(100, 100);
    game.drawBoard(&mtm);
    game.compute("5+15/5=8", &mtm);
    // EXPECT SYMBOL G = GREEN P = PURPLE. B = BLACK.
    // BBPBBBGB.
    EXPECT_TRUE(mtm.isThisBoxBlack(game.fieldCor_[0][0].first,
                            game.fieldCor_[0][0].second));
    EXPECT_TRUE(mtm.isThisBoxBlack(game.fieldCor_[0][1].first,
                            game.fieldCor_[0][1].second));
    EXPECT_TRUE(mtm.isThisBoxPurple(game.fieldCor_[0][2].first,
                            game.fieldCor_[0][2].second));
    EXPECT_TRUE(mtm.isThisBoxBlack(game.fieldCor_[0][3].first,
                            game.fieldCor_[0][3].second));
    EXPECT_TRUE(mtm.isThisBoxBlack(game.fieldCor_[0][4].first,
                            game.fieldCor_[0][4].second));
    EXPECT_TRUE(mtm.isThisBoxBlack(game.fieldCor_[0][5].first,
                            game.fieldCor_[0][5].second));
    EXPECT_TRUE(mtm.isThisBoxGreen(game.fieldCor_[0][6].first,
                            game.fieldCor_[0][6].second));
    EXPECT_TRUE(mtm.isThisBoxBlack(game.fieldCor_[0][7].first,
                            game.fieldCor_[0][7].second));
}
