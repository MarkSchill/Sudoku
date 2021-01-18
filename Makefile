CC=gcc
SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o,$(SRC))
CFLAGS=-Wall -std=c99 $(shell pkg-config --cflags ncursesw)
LDFLAGS=$(shell pkg-config --libs ncurses)

default: sudoku

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

sudoku: $(OBJ)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ) sudoku
