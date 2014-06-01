#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"


void populate(int full[display_SIZE][display_SIZE], int prob)
{
	for(int row = 0; row<display_SIZE;row++)
		for(int col=0;col<display_SIZE;col++)
			full[row][col] = (rand()%prob)==0;
}

void update(int full[display_SIZE][display_SIZE])
{
	int next[display_SIZE][display_SIZE];
	for(int row =0;row < display_SIZE;row++)
	{
		for(int col=0;col<display_SIZE;col++)
		{
			int neighbors = full[row][col]*-1;
			for(int dr=(row==0?0:-1);dr<=(row==display_SIZE?0:1);dr++)
				for(int dc=(col==0?0:-1);dc<=(col==display_SIZE?0:1);dc++)
					neighbors+=full[row+dr][col+dc];
			next[row][col] = ((full[row][col]&&neighbors==2)||neighbors==3);
		}
	}
	for(int j = 0;j<display_SIZE;j++)
		memcpy(full[j],next[j],sizeof(next[0]));
}
		

int main(int argc, char* argv[])
{
	display_init(atoi(argv[1]));
	int full[display_SIZE][display_SIZE];
	for(int row=0;row<display_SIZE;row++)
		for(int col=0;col<display_SIZE;col++)
			full[row][col]=0;
	populate(full,atoi(argv[2]));
	do{
		display_render(full);
		update(full);
	}while(display_get_char()!='q');

	display_destroy();

	return 0;
}
