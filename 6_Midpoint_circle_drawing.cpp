#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{

    double x, y, x1, y1, p,  xc, yc, r;
    cout << "Give radius of the circle: ";
    cin >> r;
    cout << "Give the center Point (x1, y1): ";
    cin >> xc >> yc;

    x = 0;
    y = r;

    p = (5.0/4.0) - r;

    x1 = xc + x;
    y1 = xc + y;
    initwindow(1000, 800, "Midpoint Circle Drawing", 300, 50);

    do{
        putpixel(xc+x, yc+y, WHITE);
        putpixel(xc+y, yc+x, WHITE);
        putpixel(xc + x, yc-y, WHITE);
        putpixel(xc+y, yc-x, WHITE);
        putpixel(xc-x, yc-y, WHITE);
        putpixel(xc-y, yc-x, WHITE);
        putpixel(xc-x, yc+y, WHITE);
        putpixel(xc-y, yc+x, WHITE);
        if(p < 0)
        {
            x = x + 1;
            p = p + 2*x + 1;

        }

        else
        {
            x = x+1;
            y = y-1;
            p = p + 2*x + 1 - 2*y;
        }

    }while(y>=x);



    getch();
    closegraph();
    return 0;
}

/*
r = 50
xc = 300
yc = 300
*/


