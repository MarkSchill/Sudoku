#ifndef SUDOKU_MENU_H
#define SUDOKU_MENU_H

#include <ncurses.h>

void menu_init(int *, int *, WINDOW **);
void menu_loop();
void menu_draw(int *, int *, WINDOW **, const char **);
void circles_draw(WINDOW *);
void menu_input(int *, int *, int *, WINDOW **);

#endif
