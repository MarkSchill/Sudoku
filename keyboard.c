#include "keyboard.h"

#include <ncurses.h>

int directional_keys(int key, int *y, int *x, int *my, int *mx) {
	// TODO: This currently does not check for the boundries of the wndow / menus (bit of an issue)

	if (key == (int) 'w' || key == (int) 'W' || key == KEY_UP) {
		if (*y >= 1)
			(*y)--;
	} else if (key == (int) 's' || key == (int) 'S' || key == KEY_DOWN) {
		if (*y < *my)
			(*y)++;
	} else if (key == (int) 'a' || key == (int) 'A' || key == KEY_LEFT) {
		if (*x >= 1)
			(*x)--;
	} else if (key == (int) 'd' || key == (int) 'D' || key == KEY_RIGHT) {
		if (*x < *mx)
			(*x)++;
	} else {
		return 0;
	}

	return 1;
}

int escape_keys(int key) {
	// Ncurses doesn't allow the use of the escape key in raw mode
	if (key == (int) 'q' || key == (int) 'Q') {
		return 1;
	}

	return 0;
}

int enter_keys(int key) {
	if (key == (int) '\n') {
		return 1;	
	}
	
	return 0;
}
