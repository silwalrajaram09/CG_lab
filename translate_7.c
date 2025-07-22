#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
void translate(int, int, int, int, int, int);
void drawtriangle(int, int, int, int, int, int);
void main()
{
	int gd = DETECT, gm;
	int x1, y1, x2, y2, x3, y3;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter the first point of the triangle");
	scanf("%d%d", &x1,&y1);
	printf("Enter the second point of the triangle");
	scanf("%d%d", &x2,&y2);
	printf("Enter the third point of the triangle");
	scanf("%d%d", &x3,&y3);
	drawtriangle (x1,y1,x2,y2,x3,y3);
	translate (x1,y1,x2,y2,x3,y3);
	getch();
	closegraph();
}
void translate(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int tx,ty;
	printf("Enter the translation factor:");
	scanf("%d%d", &tx,&ty);
	x1 += tx;
	y1 += ty;
	x2 += tx;
	y2 += ty;
	x3 += tx;
	y3 += ty;
	setcolor(RED);
	drawtriangle(x1,y1,x2,y2,x3,y3);
	
}
void drawtriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
}
