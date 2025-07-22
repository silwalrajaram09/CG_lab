#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawtriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void scaletriangle(int x1, int y1, int x2, int y2, int x3, int y3, float sx, float sy);

void main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    float sx, sy;

    initgraph(&gd, &gm, "C:\\Turboc3\\bgi");

    // Input original triangle coordinates
    printf("Enter the first point of the triangle: ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the second point of the triangle: ");
    scanf("%d%d", &x2, &y2);
    printf("Enter the third point of the triangle: ");
    scanf("%d%d", &x3, &y3);

    drawtriangle(x1, y1, x2, y2, x3, y3);

    // Input scaling factors
    printf("Enter scaling factors (sx and sy): ");
    scanf("%f%f", &sx, &sy);

    // Draw scaled triangle
    setcolor(WHITE);
    scaletriangle(x1, y1, x2, y2, x3, y3, sx, sy);

    getch();
    closegraph();
}

void drawtriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void scaletriangle(int x1, int y1, int x2, int y2, int x3, int y3, float sx, float sy)
{
    int x1s, y1s, x2s, y2s, x3s, y3s;

    // Scaling with respect to origin (0, 0)
    x1s = x1 * sx;
    y1s = y1 * sy;

    x2s = x2 * sx;
    y2s = y2 * sy;

    x3s = x3 * sx;
    y3s = y3 * sy;

    drawtriangle(x1s, y1s, x2s, y2s, x3s, y3s);
}
