#include <ncurses.h>
#include "display.h"

int display_SIZE = 10;

void display_init(int size)
{
	initscr();
	raw();
	noecho();
	display_SIZE = size;
}

void display_destroy()
{
	endwin();
}

int display_get_char()
{
	return getch();
}

void display_render(int full[display_SIZE][display_SIZE])
{
	for(int row =0; row < display_SIZE;row++)
		for(int col = 0; col < display_SIZE;col++)
			mvaddch(row,col,full[row][col] + '0');
	refresh();
}
