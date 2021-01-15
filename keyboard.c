#include "keyboard.h"

#include <ncurses.h>

int is_directional_keys(int key) {
	if (key == (int) 'w' || key == (int) 'W' || key == KEY_UP) {
	} else if (key == (int) 's' || key == (int) 'S' || key == KEY_DOWN) {
	} else if (key == (int) 'a' || key == (int) 'A' || key == KEY_LEFT) {
	} else if (key == (int) 'd' || key == (int) 'D' || key == KEY_RIGHT) {
	} else {
		return 0;
	}

	return 1;
}

int is_escape_keys(int key) {
	// Ncurses doesn't allow the use of the escape key in raw mode
	if (key == (int) 'q' || key == (int) 'Q') {
		return 1;
	}

	return 0;
}

int is_enter_keys(int key) {
	if (key == (int) '\n') {
		return 1;	
	}
	
	return 0;
}
