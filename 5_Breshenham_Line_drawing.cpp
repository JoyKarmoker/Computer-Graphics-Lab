#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{

    int x1, y1, x2, y2, p, dy, dx, x, y, xend, yend;
    cout << "Give endpoints of the line: ";
    cout << "Point (x1, y1): ";
    cin >> x1 >> y1;

    cout << "Point (x2, y2): ";
    cin >> x2 >> y2;

    dx = abs(x1-x2);
    dy = abs(y1-y2);

    p = 2*dy - dx;

    if(x1>x2)
    {
        x = x2;
        y = y2;
        xend = x1;
        yend = x1;
    }

    else
    {
        x = x1;
        y = y1;
        xend = x2;
        yend = y2;
    }

     initwindow(1000, 800, "Bresenham Line Drawing", 300, 50);
     putpixel(x, y, WHITE);
    while(x < xend)
    {
        x++;
        if(p < 0 )
        {
            p = p + (2 * dy);
        }

        else
        {
            if(yend > y)
            {
                y = y+1;
            }
            else
            {
                y = y-1;
            }

            p = p + 2*dy - 2*dx;
        }
         putpixel(x, y, WHITE);
    }


    getch();
    closegraph();
    return 0;
}

/*
200 400
300 300
*/

/*
200 400
300 500
*/
