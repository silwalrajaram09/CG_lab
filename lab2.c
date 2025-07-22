#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void main()
{
    int gd = DETECT, gm, i;
    int x, y, dx, dy, p;
    int x0, x1, y0, y1;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("Enter co-ordinates of first point: ");
    scanf("%d%d", &x0, &y0);
    printf("Enter co-ordinates of second point: ");
    scanf("%d%d", &x1, &y1);

    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;
    p = 2 * dy - dx;

    while (x < x1)
    {
        x++;
        if (p < 0)
            p = p + 2 * dy;
        else
        {
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        delay(10);
        putpixel(x, y, WHITE);
    }
    getch();
    closegraph();
}
