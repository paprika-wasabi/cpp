// Copyright 2022, University of Freiburg
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>

#ifndef SNAKE_H_
#define SNAKE_H_

// The total number of logical pixels on the screen.
extern int numPixelsX;
extern int numPixelsY;

// Space characters are not squares, so we draw several of them for
// one pixel.
const int pixelWidth = 2;
const int pixelHeight = 1;


const int SNAKE_LENGTH = 13;

// The positions of the segments of the snake in pixels. At index 0 there is
// the head and at index SNAKE_LENGTH - 1 there is the tail.
extern int  posX[SNAKE_LENGTH];
extern int  posY[SNAKE_LENGTH];


// The x and y component of the direction of the snake. vx * vx + vy * vy == 1
// must hold (the direction must be normalized), otherwise the speed is not
// correct (see moveSnake function).
extern int vx;
extern int vy;

extern int newVx;
extern int newVy;

// ___________________________________________________________________________

// Initialize the terminal for use with ncurses commands.
void initTerminal();

// Initialize the snake.
void initSnake();

// Draw a pixel at the position given by y and x. Note that a pixel consists of
// multiple space characters, depending on `pixelWidth` and `pixelHeight`.
void drawPixel(int y, int x);

// Draw the snake (show == true: draws in black, show == true: draws in white).
void drawSnake(bool show);

// Draw a border around the screen.
void drawBorder();


// Return true iff the head of the snake is on our out of the border
bool collidesWithBorder();

// Return true iff the head of the snake is on the same pixel as another segment
// of the snake.
bool collidesWithSelf();

// Update the position of the  snake when `milliseconds` have passed since the
// last call to `moveSnake`
void moveSnake();

// Update the direction and the speed of the snake given the last pressed key.
// Return false if `escape` was pressed, return true for any other key.
bool handleKey(int key);

#endif  // SNAKE_H_

