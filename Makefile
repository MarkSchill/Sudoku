CC=gcc
SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o,$(SRC))
CFLAGS=-Wall -std=c99 $(shell pkg-config --cflags ncursesw)
LDFLAGS=

default: clean sudoku

sudoku:
	$(CC) $(SRC) -o $@ $(CFLAGS) $(shell pkg-config --libs ncursesw) -lncursesw

clean:
	rm -f $(OBJ) sudoku
