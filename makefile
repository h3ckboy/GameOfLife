main: main.c display.c display.h
	c99 -c main.c display.c
	c99 -o main main.o display.o -lncurses
