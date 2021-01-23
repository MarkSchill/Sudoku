#include "game.h"

#include <ncurses.h>
#include "keyboard.h"

void game_draw(int *my, int *mx, int *y, int *x) {
	int width = (9 * 2) - 2;
	int height = (9 * 2) - 2;
	int grid_x = (*mx / 2) - (width / 2);
	int grid_y = (*my / 2) - (height / 2);

	WINDOW *grid = newwin(height, width, grid_y, grid_x);
	box(grid, 0, 0);

	refresh();

	wrefresh(grid);

	move(*y, *x);
}

void game_input(int *game_running, int *y, int *x, int *my, int *mx) {
	int key = getch();

	if (key == KEY_UP) {
		(*y) --;
	} else if (key == KEY_DOWN) {
		(*y) ++;
	} else if (key == KEY_LEFT) {
		(*x) --;
	} else if (key == KEY_RIGHT) {
		(*x) ++;
	}

	if (key >= '0' && key <= '9') {
		// Enter the given number into the current cell based on x & y
	}

	if (is_escape_keys(key)) {
		*game_running = 0;
	}
}

void game_loop(int *my, int *mx) {
	int running = 1;

	int y, x;
	y = x = 0;

	clear();

	// Set the cursor to 'very visible'
	curs_set(2);

	// Set blocking on read
	timeout(0);

	while (running) {
		game_draw(my, mx, &y, &x);
		game_input(&running, &y, &x, NULL, NULL);
	}
}
