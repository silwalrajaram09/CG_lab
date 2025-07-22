#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
void boundaryfill(int x,int y, int fcolor, int bcolor)
{
	if(getpixel(x,y)!=bcolor && getpixel(x,y)!=fcolor)
	{
		delay(1);
		putpixel(x,y,fcolor);
		boundaryfill(x+1,y,fcolor,bcolor);
		boundaryfill(x,y+1,fcolor,bcolor);
		boundaryfill(x-1,y,fcolor,bcolor);
		boundaryfill(x,y-1,fcolor,bcolor);
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
	boundaryfill(x,y,GREEN,RED);
	getch();
	closegraph();
}