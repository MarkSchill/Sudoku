#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H

#include <ncurses.h>

void game_loop();
void game_init(int *, int *, WINDOW **);
void game_input(int *, int *, int *, WINDOW *);
void game_draw(int *, int *, WINDOW *);

// void game_serialize();

#endif
