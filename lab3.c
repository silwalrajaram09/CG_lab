#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void symmetry(int, int, int, int);

void main() {
    int gd = DETECT, gm, i;
    int x, y, r, xc, yc, p;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    
    printf("Enter co-ordinates of first point center: ");
    scanf("%d%d", &xc, &yc);
    
    printf("Enter radius: ");
    scanf("%d", &r);
    
    x = 0;
    y = r;
    p = 1 - r;

    for (x = 0; y > x; x++) {
        if (p < 0)
            p = p + 2 * x + 1;
        else {
            p = p + 2 * (x - y) + 1; 
            y--;
        }
        delay(10);
        symmetry(x,y,xc,yc);
    }
    getch();
    closegraph();
}
void symmetry(int x, int y, int xc, int yc)
{
	putpixel(xc+x,yc+y,WHITE);	
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	putpixel(xc+y,yc+x,WHITE);
	putpixel(xc-y,yc+x,WHITE);
	putpixel(xc+y,yc-x,WHITE);
	putpixel(xc-y,yc-x,WHITE);
}
