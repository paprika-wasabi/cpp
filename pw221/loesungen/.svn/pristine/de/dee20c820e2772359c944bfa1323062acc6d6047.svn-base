// Copyright 2022, University of Freiburg
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Johannes Kalmbach <kalmbach@cs.uni-freiburg.de>

#include <ncurses.h>
#include "./Snake.h"

// ____________________________________________________________________________
// Global variables. See the header for documentation.
//
int posX[SNAKE_LENGTH];
int posY[SNAKE_LENGTH];

int vx;
int vy;

int newVx;
int newVy;

int numPixelsX;
int numPixelsY;


// ____________________________________________________________________________
void initTerminal() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);

  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLUE);
  init_pair(2, COLOR_RED, COLOR_BLACK);

  // COLS and LINES are global variables from ncurses (dimensions of screen).
  numPixelsX = COLS / pixelWidth;
  numPixelsY = LINES / pixelHeight;
}

// ____________________________________________________________________________
void initSnake() {
  for (int i = 0; i < SNAKE_LENGTH; i++) {
    posX[i] = SNAKE_LENGTH - i;
    posY[i] = numPixelsY / 2;
  }

  vx = 1;
  vy = 0;
  newVx = vx;
  newVy = vy;
}

// _____________________________________________________________________________
void drawPixel(int y, int x) {
  for (int i = 0; i < pixelHeight; i++) {
    for (int j = 0; j < pixelWidth; j++) {
      mvprintw(y * pixelHeight + i, x * pixelWidth + j, " ");
    }
  }
}

// ____________________________________________________________________________
void drawBorder() {
  attron(COLOR_PAIR(1));
  attron(A_REVERSE);
  for (int x = 0; x < numPixelsX; x++) {
    drawPixel(0, x);
    drawPixel(numPixelsY - 1, x);
  }

  for (int y = 0; y < numPixelsY; y++) {
    drawPixel(y, 0);
    drawPixel(y, numPixelsX - 1);
  }
  attroff(A_REVERSE);
  attroff(COLOR_PAIR(1));
}

// ____________________________________________________________________________
void drawSnake(bool show) {
  if (show == true) attron(A_REVERSE);
  for (int i = 1; i < SNAKE_LENGTH; i++) {
    drawPixel(posY[i], posX[i]);
  }

  attron(COLOR_PAIR(2));
  drawPixel(posY[0], posX[0]);
  attroff(COLOR_PAIR(2));

  attroff(A_REVERSE);
}

// ____________________________________________________________________________
bool collidesWithBorder() {
  int x = posX[0];
  int y = posY[0];
  return x <= 0 || x >= numPixelsX - 1 || y <= 0 || y >= numPixelsY - 1;
}

// ____________________________________________________________________________
bool collidesWithSelf() {
  int x = posX[0];
  int y = posY[0];

  for (int i = 1; i < SNAKE_LENGTH; i++) {
    if (x == posX[i] && y == posY[i]) {
      return true;
    }
  }
  return false;
}


// ____________________________________________________________________________
void moveSnake() {
  if (newVx + vx != 0 || newVy + vy != 0) {
    vx = newVx;
    vy = newVy;
  }

  for (int i = SNAKE_LENGTH - 1; i > 0; i--) {
    posX[i] = posX[i - 1];
    posY[i] = posY[i - 1];
  }

  posX[0] = posX[0] + vx;
  posY[0] = posY[0] + vy;
}

// ____________________________________________________________________________
bool handleKey(int key) {
  switch (key) {
    case 27:  // ESC
      return false;
    case KEY_DOWN:
      newVx = 0;
      newVy = 1;
      break;
    case KEY_UP:
      newVx = 0;
      newVy = -1;
      break;
    case KEY_LEFT:
      newVx = -1;
      newVy = 0;
      break;
    case KEY_RIGHT:
      newVx = 1;
      newVy = 0;
      break;
    default:
      break;
  }

  return true;
}

