#include "game.h"

#include <ncurses.h>
#include "keyboard.h"

void game_draw() {
	
}

void game_input(int *game_running, int *y, int *x, int *my, int *mx) {
	int key = getch();

	if (is_escape_keys(key)) {
		*game_running = 0;
	}
}

void game_loop(int *my, int *mx) {
	int running = 1;

	int y, x;
	y = x = 0;

	clear();

	while (running) {
		game_input(&running, &y, &x, my, mx);
	}
}
