#include <ncurses.h>
#include "menu.h"

int main(int argc, char *argv[]) {
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	// Get the size of the terminal window
	int my, mx;
	getmaxyx(stdscr, my, mx);

	menu_loop(&my, &mx);

	endwin();
    return 0;
}
