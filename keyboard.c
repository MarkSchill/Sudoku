#include "keyboard.h"

#include <ncurses.h>

int get_input() {
	int k = getch();

	if (k >= KEY_DOWN && k <= KEY_RIGHT) {
		// Do nothing
	} else if (k >= (int) '0' && k <= (int) '9') {
		// Also do nothing
	} else if (k == (int) '\n') {
		k = KEY_ENTER;
	} else if (k == (int) 'q' || k == (int) 'Q') {
		k = KEY_EXIT;
	} else {
		// Invalid key, returns zero
		k = 0;
	}

	return k;
}
