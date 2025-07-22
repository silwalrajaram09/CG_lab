//write a c program to make a stickman game to enter the house.
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
void drawhouse()
{
	rectangle (200,200,300,300);
	line(200,200,250,150);
	line(250,150,300,200);
	rectangle(230,250,270,300);
}
void drawCharacter(int x, int y)
{
	setcolor(WHITE);
	circle(x,y,10);
	line(x, y+10, x, y+30);
	line(x, y+30, x-10, y+40);
	line(x, y+30, x+10, y+40);
	line(x, y+15, x-10, y+20);
	line(x, y+15, x+10, y+20);
}
void clearCharacter(int x, int y)
{
	setcolor(BLACK);
	circle(x,y,10);
	line(x, y+10, x, y+30);
	line(x, y+30, x-10, y+40);
	line(x, y+30, x+10, y+40);
	line(x, y+15, x-10, y+20);
	line(x, y+15, x+10, y+20);
}
void main()
{
	int gd= DETECT, gm, i;
	int x=100, y=250;
	char key;
	initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");
	drawhouse();
	drawCharacter(x,y);
	while(1)
	{
		if(kbhit())
		{
			key=getch();
			clearCharacter(x,y);
			if(key==72) y-=10; //up arrow key
			if(key==80) y+=10; //down arrow key
			if(key==75) x-=10; //left arrow key
			if(key==77) x+=10; //right arrow key
			drawCharacter(x,y);
			if(x>200 && x<300 && y>200 && y<300)
			{
				setcolor(RED);
				outtextxy(200,350,"GAME OVER !!!!");
				break;
			}
		}
	}
	getch();
	delay(500);
}