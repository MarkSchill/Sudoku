#include <ncurses.h>
#include "menu.h"

int main(int argc, char *argv[]) {
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	menu_loop();

	endwin();
    return 0;
}
