#include "menu.h"

#include <ncurses.h>
#include "keyboard.h"
#include "game.h"

int n_items = 3;
const char *items[] = { "Start new", "Resume", "Quit" };

// Might need to create a global variable for the WINDOW structures to allow 'menu_input'
// to call wgetch() instead of getch()

void menu_input(int *menu_running, int *y, int *x, int *my, int *mx) {
	int key = getch();

	if (key == KEY_UP) {
		if (*y >= 1)
			(*y) --;
	} else if (key == KEY_DOWN) {
		if (*y < n_items - 1)
			(*y) ++;
	}

	if (is_enter_keys(key)) {
		if (*y == 0) {
			// Start the game loop
			game_loop(my, mx);

			// Clear the screen and start displaying the menu again
			clear();

			timeout(1000);

			curs_set(0);
		} else if (*y == 1) {
			// Resume
		} else if (*y == 2) {
			// Quit
			*menu_running = 0;
		}
	}
	
	if (is_escape_keys(key)) {
		*menu_running = 0;
	} 
}

void menu_draw(int *y, int *x, int *my, int *mx) {
	int width = 30;
	int height = 11;
	int box_x = (*mx / 2) - (width / 2);
	int box_y = (*my / 2) - (height / 2);

	WINDOW *middle = newwin(height, width, box_y, box_x);
	box(middle, 0, 0);

	WINDOW *circles = newwin(9, 9, box_y + 1, box_x + 18);
	box(circles, 0, 0);

	// static int data[9];

	int i;
	for (i = 0; i < n_items; i++) {
		mvwprintw(middle, i + 1, 1, "[%c] %s", (i == *y ? 'x' : ' '), items[i]);
	}

	wrefresh(middle);


	// Create timer to make sure this runs at a certain speed
	// Highlight random tiles in the background of the 'circles' window

	//for (i = 0; i < 9; i++) {
		mvprintw(box_y + 1, box_x + 18, "X");
	//}
	
	wrefresh(circles);

	move(*y + box_y + 1, *x + box_x + 1);
}

void menu_loop(int *my, int *mx) {
	int menu_running = 1;

	int y, x;
	y = x = 0;


	// Make cursor invisible
	curs_set(0);

	// Create timeout on the keyboard input so that it allows the 'circles' window to repaint and update
	// TODO: MAKE SURE TO TURN OFF THE TIMEOUT WHEN THE ACTUAL GAME STARTS
	timeout(1000);

	while (menu_running) {
		menu_draw(&y, &x, my, mx);
		menu_input(&menu_running, &y, &x, my, mx);

		// Test to see how many times this loops per second
		//mvprintw();
	}
}
