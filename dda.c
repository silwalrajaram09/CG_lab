#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
void main(){
	int gd= DETECT, gm=i;
	float x,y,dy,dx,steps;
	int x0,x1,y0,y1;
	initgraph(&gd,&gm,"C:\\Turboc3\\bgi");
	printf("Enter co-ordinate of first point");
	scanf("%d %d",&x0,&y0);
	printf("Enter co-ordinate of second point");
	scanf("%d %d",&x1,&y1);
	dx= x1-x0;
	dy= y1-y0;
	if(abs(dx)>=abs(dy))
		steps= abs(dx);
	else
		steps= abs(dy);
	
	dx= dx/steps;
	dy= dy/steps;
	x=x0;
	y=y0;
	for(i=1; i<=steps; i++){
		putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
		x += dx;
       		y += dy;
		delay(10);
	}
	 getch();
   	 closegraph();
	
}
