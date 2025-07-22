#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
void flood_fill(int x,int y, int fillcolor, int oldcolor)
{
	if(getpixel(x,y)==oldcolor)
	{
		delay(1);
		putpixel(x,y,fillcolor);
		flood_fill(x+1,y,fillcolor,oldcolor);
		flood_fill(x,y+1,fillcolor,oldcolor);
		flood_fill(x-1,y,fillcolor,oldcolor);
		flood_fill(x,y-1,fillcolor,oldcolor);
	}
}
void main()
{
	int gd = DETECT, gm, x, y;
	initgraph (&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter the seed point: ");
	scanf("%d%d", &x, &y);
	setcolor (RED);
	rectangle(100,100,150,150);
	flood_fill(x,y,BLUE,BLACK);
	getch();
	closegraph();
}