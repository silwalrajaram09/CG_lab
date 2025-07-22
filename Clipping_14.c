

#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

void main()
{
    int rcode1[4] = {0, 0, 0, 0}, rcode2[4] = {0, 0, 0, 0}, rcode[4];
    int wxmax, wymax, wxmin, wymin, flag = 0;
    float slope;
    int x, y, x1, y1, i, xc, yc;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("\n Now, enter XMin, YMin =");
    scanf("%d %d", &wxmin, &wymin);
    printf("\n First enter XMax, YMax =");
    scanf("%d %d", &wxmax, &wymax);
    printf("\n Please enter initial point x and y= ");
    scanf("%d %d", &x, &y);
    printf("\n Now, enter final point x1 and y1= ");
    scanf("%d %d", &x1, &y1);
    
    cleardevice();
    rectangle(wxmin, wymin,wxmax,wymax);
    line(x, y, x1, y1);

    if (y > wymax) {
        rcode1[0] = 1;  // Top
        flag = 1;
    }
    if (y < wymin) {
        rcode1[1] = 1;
		flag = 1; 		// Bottom
    }
    if(x > wxmax){
    	rcode1[2]=1;	//right
    	flag=1;
	}
	if(x < wxmin){
		rcode1[3]=1;	//left
		flag=1;
	}
	
	if (y1 > wymax) {
        rcode2[0] = 1;  // Top
        flag = 1;
    }
    if (y1 < wymin) {
        rcode2[1] = 1;  // Bottom
    }
    if(x1 > wxmax) {
    	rcode2[2]=1;	//right
    	flag=1;
	}
	if(x1 < wxmin) {
		rcode2[3]=1;	//left
		flag=1;
	}
	if (flag == 0)
    	printf("No need of clipping as it is already in window");
	flag = 1;

	for (i = 0; i < 4; i++) {
    	rcode[i] = rcode1[i] && rcode2[i];
    	if (rcode[i] == 1)
        flag = 0;
	}

	if (flag == 0) 
	{
    	printf("\n Line is completely outside the window");
	} 
	else {
	    slope = (float) (y1 - y) / (x1 - x);
	    if (rcode1[2] == 0 && rcode1[3] == 1) // left
	    {
	        y = y + (float) (wxmin - x) * slope;
	        x = wxmin;
	    }
	     if (rcode1[2] == 1 && rcode1[3] == 0) // right
	    {
	        y = y + (float) (wxmax - x) * slope;
	        x = wxmax;
	    }
	     if (rcode1[0] == 1 && rcode1[1] == 0) // top
	    {
	        x = x + (float) (wymax - y) / slope;
	        y = wymax;
	    }
	     if (rcode1[0] == 0 && rcode1[1] == 1) // bottom
	    {
	        x = x + (float) (wymin - y) / slope;
	        y = wymin;
	    }
	    
	     if (rcode2[2] == 0 && rcode2[3] == 1) // left
	    {
	        y1 = y1 + (float) (wxmin - x1) * slope;
	        x1 = wxmin;
	    }
	     if (rcode2[2] == 1 && rcode2[3] == 0) // right
	    {
	        y1 = y1 + (float) (wxmax - x1) * slope;
	        x1 = wxmax;
	    }
	     if (rcode2[0] == 1 && rcode2[1] == 0) // top
	    {
	        x1 = x1 + (float) (wymax - y1) / slope;
	        y1 = wymax;
	    }
	     if (rcode2[0] == 0 && rcode2[1] == 1) // bottom
	    {
	        x1 = x1 + (float) (wymin - y1) / slope;
	        y1 = wymin;
	    }
	}
	getch();
	clearviewport();
	rectangle(wxmin,wymin,wxmax,wymax);
	setcolor(RED);
	line(x,y,x1,y1);
	getch();
	closegraph();
}
