#include "menu.h"

#include <ncurses.h>
#include "keyboard.h"

int n_items = 3;
const char *items[] = { "Start new", "Resume", "Quit" };

void menu_input(int *menu_running, int *y, int *x) {
	int key = getch();

	if (directional_keys(key, y, x, 0, &n_items)) {
	} else if (escape_keys(key)) {
		// Stop the menu loop
		*menu_running = 0;
	} else {
		// Unkown key
		// Print an error somewhere

		// mvprintw(pos_y, pos_x, "Unknown input '%c'", key);
	}
}

void menu_draw(int *y, int *x, int *my, int *mx) {
	// Draw the debug / information overlay
	//overlay_draw(my, mx);

	// Draw a box in the middle of the screen
	//border(0, 0, 0, 0, 0, 0, 0, 0);
	WINDOW *middle = newwin(20, 20, 20, 20);
	box(middle, '*', '*');
	touchwin(middle);
	wrefresh(middle);

	// Move the terminal cursor to y, x
	wmove(stdscr, *y, *x);

	int i;
	for (i = 0; i < n_items; i++) {
		printw("%d. %s\n", i + 1, items[i]);
	}

	// Print the current position of the terminal cursor
	//  (mainly for debugging)
	mvprintw(*my - 1, *mx - 10, "(%d, %d)", *y, *x);

	// Refresh the curses screen
	refresh();
}

void menu_loop(int *my, int *mx) {
	int menu_running = 1;

	// X and y coordinates to keep track of where the terminal cursor is
	int y, x;
	y = x = 0;

	while (menu_running) {
		menu_draw(&y, &x, mx, my);
		menu_input(&menu_running, &y, &x);
	}
}
