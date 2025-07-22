#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void symmetry(int, int, int, int);

void main() {
    int gd = DETECT, gm;
    float x, y, p1, p2;
    int xc, yc, rx, ry;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("Enter co-ordinates of center: ");
    scanf("%d%d", &xc, &yc);
    printf("Enter values of rx and ry: ");
    scanf("%d%d", &rx, &ry);

    x = 0;
    y = ry;

    p1 = ry*ry - rx*rx*ry + rx*rx/4;

    while (2*ry*ry*x<=2*rx*rx*y) 
	{
        x++;
        if (p1 <= 0) 
            p1+=2*ry*ry*x+ry*ry;
        else 
		{
            y--;
            p1+=2*ry*ry*x-2*rx*rx*y+ry*ry;
        }
        symmetry(x,y,xc,yc);
	}
	x=rx;
	y=0;
	p2 = rx*rx -ry*ry*rx + ry*ry/4;
    while (2*ry*ry*x > 2*rx*rx*y)
	{
        y++;
        if (p2 <= 0) {
        	x--;
            p2+=2*ry*ry*x-2*rx*rx*y + rx*rx;
        } 
		else 
            p2 += rx*rx - 2*rx*rx*y;
        symmetry(x,y,xc,yc);
	}
	getch();
    closegraph();	
}
void symmetry (int x, int y, int xc, int yc)
{
	delay(10);
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
}