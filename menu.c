#include "menu.h"

#include <ncurses.h>
#include "keyboard.h"
#include "game.h"

int n_items = 3;
const char *items[] = { "Start new", "Resume", "Quit" };

void menu_input(int *menu_running, int *y, int *x, int *my, int *mx) {
	int key = getch();

	if (key == KEY_UP) {
		if (*y >= 1)
			(*y) --;
	} else if (key == KEY_DOWN) {
		if (*y < n_items - 1)
			(*y) ++;
	} else if (is_escape_keys(key)) {
		*menu_running = 0;
	} else if (is_enter_keys(key)) {
		if (*y == 0) {
			game_loop(my, mx);
		} else if (*y == 1) {
			// Resume the old game
		} else if (*y == 2) {
			*menu_running = 0;
		}
	}
}

void menu_draw(int *y, int *x, int *my, int *mx) {
	int width = 30;
	int height = 7;
	int box_x = (*mx / 2) - (width / 2);
	int box_y = (*my / 2) - (height / 2);

	WINDOW *middle = newwin(height, width, box_y, box_x);
	box(middle, 0, 0);

	WINDOW *circles = newwin(5, 8, box_y + 1, box_x + 18);
	box(circles, 0, 0);

	int i;
	for (i = 0; i < n_items; i++) {
		mvwprintw(middle, i + 1, 1, "%d. %s", i + 1, items[i]);
	}
	
	//TODO: Maybe move this to overlay.c
	mvprintw(*my - 1, *mx - 10, "(%d, %d)", *y, *x);

	wrefresh(middle);
	wrefresh(circles);

	wmove(middle, *y + 1, *x + 1);

	refresh();
}

void menu_loop(int *my, int *mx) {
	int menu_running = 1;

	int y, x;
	y = x = 0;

	while (menu_running) {
		menu_draw(&y, &x, my, mx);
		menu_input(&menu_running, &y, &x, my, mx);
	}
}
