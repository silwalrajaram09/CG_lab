#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void main()
{
    int gd = DETECT, gm, i;
    int tx=100, ty=120;
    int left=50, top=150, right=150, bottom=200, depth=50;
    initgraph(&gd, &gm, "C:\\Turboc3\\bgi");

    bar3d(left, top, right, bottom, depth, 1);
    getch();
    //bar3d(left+tx, top+ty, right+tx, bottom+ty, depth, 1);
	bar3d(left*2,top*2,right*2,bottom*2,depth*2,1);
    getch();
    closegraph();
}
