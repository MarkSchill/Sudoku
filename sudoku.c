#include <ncurses.h>
#include "menu.h"

int main(int argc, char *argv[]) {
	// Initialize the curses screen
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	// Get the size of the terminal window
	int my, mx;
	getmaxyx(stdscr, my, mx);

	// Start the main menu loop
	menu_loop(&my, &mx);

	// Duh
	endwin();
    return 0;
}
