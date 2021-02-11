#include "menu.h"

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#include "keyboard.h"
#include "game.h"

void menu_init(int *y, int *x, WINDOW **windows) {
	clear();

	*y = *x = 0;
	
	// Setting the cursor to invisible
	curs_set(0);

	// Activate non-blocking timeout for keyboard input
	timeout(1000);

	int max_y = 0, max_x = 0;
	getmaxyx(stdscr, max_y, max_x);

	// Initiallizing the windows array
	int width = 30;
	int height = 13;
	int box_x = (max_x / 2) - (width / 2);
	int box_y = (max_y / 2) - (height / 2);

	windows[0] = newwin(height, width, box_y, box_x);
	windows[1] = newwin(11, 11, box_y + 1, box_x + 16);
}

void menu_loop() {
	int menu_running = 1;
	int y = 0, x = 0;
	WINDOW *warr[2];
	const char *items[] = { "Start new", "Resume", "Quit", NULL };

	// Set seed for rand() function
	srand(time(NULL));

	menu_init(&y, &x, warr);

	while (menu_running) {
		menu_draw(&y, &x, warr, items);
		menu_input(&y, &x, &menu_running, warr);
	}
}

void menu_draw(int *y, int *x, WINDOW **windows, const char **items) {
	box(windows[0], 0, 0);
	box(windows[1], 0, 0);

	wattron(windows[0], A_BOLD | A_UNDERLINE);
	mvwprintw(windows[0], 1, 1, "Sudoku");
	wattroff(windows[0], A_BOLD | A_UNDERLINE);

	// Print menu items
	int i;
	for (i = 0; items[i] != NULL; i++) {
		mvwprintw(windows[0], i + 2, 1, "[%c] %s", (i == *y ? 'x' : ' '), items[i]);
	}

	circles_draw(windows[1]);

	refresh();
	wrefresh(windows[0]);
	wrefresh(windows[1]);
}

// TODO: Fix this
void circles_draw(WINDOW *w) {
	static int data[81];

	data[rand() % 82] = 1;

	int filled = 1;

	int i;
	for (i = 0; i < sizeof(data)/sizeof(int); i++) {
		if (data[i] == 0) {
			filled = 0;
			break;
		}
	}

	if (filled) {
		bzero(data, sizeof(data));
	}

	int cy, cx;
	for (cy = 0; cy < 9; cy++) {
		for (cx = 0; cx < 9; cx++) {
			if (data[cy * 9 + cx]) {
				mvwprintw(w, cy + 1, cx + 1, "X");
			}
		}
	}
}

void menu_input(int *y, int *x, int *menu_running, WINDOW **warr) {
	int k = get_input();

	if (k == KEY_UP) {
		if (*y >= 1)
			(*y)--;
	} else if (k == KEY_DOWN) {
		if (*y <= 1)
			(*y)++;
	}

	if (k == KEY_ENTER) {
		if (*y == 0) {
			// Start
			game_loop();

			// Setup the menu settings again
			menu_init(y, x, warr);
		} else if (*y == 1) {
			// Resume
		} else if (*y == 2) {
			// Quit
			*menu_running = 0;
		}
	}
	
	if (k == KEY_EXIT) {
		*menu_running = 0;
	}
}
