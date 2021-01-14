#include "game.h"

#include <ncurses.h>
#include <locale.h>

void draw_grid() {
	printw("┏━━━┯━━━┯━━━┳━━━┯━━━┯━━━┳━━━┯━━━┯━━━┓");
}

void game_draw() {

}

void game_loop() {
	int game_loop = 1;
	while (game_loop) {
		clear();
		draw_grid();
		refresh();


		// TODO: Remove this and create a new source file that handles keyboard interaction
		int c = getch();
		if (c == (int) 'q') {
			game_loop = 0;
		}
		// Get input
	}
}
