#include "game.h"

#include <ncurses.h>

void game_loop() {
	int running = 1;
	WINDOW *w;
	int y, x;

	game_init(&y, &x, &w);

	while (running) {
		game_draw(&y, &x, w);
		game_input(&y, &x, &running, w);
	}
}

void game_init(int *y, int *x, WINDOW **w) {
	*y = *x = 0;

	clear();

	// Set the cursor to 'very visible'
	curs_set(2);

	// Set blocking on read
	timeout(0);

	int max_y, max_x;
	getmaxyx(stdscr, max_y, max_x);

	int width = (9 * 2) + 2;
	int height = (9 * 2) + 2;
	int grid_x = (max_x / 2) - (width / 2);
	int grid_y = (max_y / 2) - (height / 2);
	*w = newwin(height, width, grid_y, grid_x);
}

void game_draw(int *y, int *x, WINDOW *w) {
	box(w, 0, 0);

	mvwaddch(w, *y, *x, ACS_VLINE);

	refresh();
	wrefresh(w);

	move(*y, *x);
}

void game_input(int *y, int *x, int *running, WINDOW *w) {
	int k = getch();

	if (k == KEY_UP) {
		(*y) --;
	} else if (k == KEY_DOWN) {
		(*y) ++;
	} else if (k == KEY_LEFT) {
		(*x) --;
	} else if (k == KEY_RIGHT) {
		(*x) ++;
	}

	if (k >= '0' && k <= '9') {
		// Enter the given number into the current cell based on *x & *y
	}

	if (k == (int) 'q') {
		*running = 0;
	}
}
