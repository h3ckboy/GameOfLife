#include <stdio.h>
#include <stdlib.h>
#include "display.h"


void populate(int full[display_SIZE][display_SIZE])
{
	for(int row = 0; row<display_SIZE;row++)
		for(int col=0;col<display_SIZE;col++)
			full[row][col] = rand()%2;
}

void update(int full[display_SIZE][display_SIZE])
{
	for(int row =0;row < display_SIZE;row++)
	{
		for(int col=0;col<display_SIZE;col++)
		{
			int neighbors = -1;
			for(int dr=(row==0?0:-1);dr<=(row==display_SIZE?0:1);dr++)
				for(int dc=(col==0?0:-1);dc<=(col==display_SIZE?0:1);dc++)
					neighbors+=full[row+dr][col+dc];
			full[row][col] = ((full[row][col]==1&&neighbors==2)||neighbors==3);
		}
	}
}
		

int main()
{
	display_init();
	int full[display_SIZE][display_SIZE];
	for(int row=0;row<display_SIZE;row++)
		for(int col=0;col<display_SIZE;col++)
			full[row][col]=0;
	populate(full);
	do{
		display_render(full);
		update(full);
	}while(display_get_char()!='q');

	display_destroy();

	return 0;
}
