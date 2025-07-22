#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
void rotate(int, int, int, int, float);
void drawtriangle(int,int,int,int,int,int);
void rotatetriangle(int, int, int, int, int, int, float);

void main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3, deg;
    float rad;
    
    initgraph(&gd, &gm, "C:\\Turboc3\\bgi");
    printf("Enter the first point for the line");
    scanf("%d%d", &x1, &y1);
    printf("Enter the second point for the line");
    scanf("%d%d", &x2, &y2);
    printf("Enter the third point for the line");
    scanf("%d%d", &x3, &y3);
    drawtriangle(x1, y1, x2, y2, x3, y3);
    printf("Enter the rotation angle");
    scanf("%d", &deg);
    rad = deg * 3.14 / 180;
    rotatetriangle(x1, y1, x2, y2, x3, y3, rad);
    getch();
}

void drawtriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	line (x1,y1,x2,y2);
	line (x2,y2,x3,y3);
	line (x1,y1,x3,y3);
}
void rotate(int x1, int y1, int x2, int y2, float rad)
{
	int x0, y0, x, y;
	x0=x1*cos(rad)-y1*sin(rad);
	y0=x1*sin(rad)+y1*cos(rad);
	x=x2*cos(rad)-y2*sin(rad);
	y=x2*sin(rad)+y2*cos(rad);
	line(x0,y0,x,y);
}
void rotatetriangle(int x1, int y1, int x2, int y2, int x3, int y3, float rad)
{
	rotate(x1,y1,x2,y2,rad);
	rotate(x2,y2,x3,y3,rad);
	rotate(x3,y3,x1,y1,rad);
}