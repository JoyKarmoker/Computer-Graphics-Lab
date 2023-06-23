#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{

    float  x1, y1, x2, y2, x3, y3, x4, y4, length, xr, yr, x, y;
    cout << "Give origin x value: ";
    cin >> x1;
    cout << "Give origin y value: ";
    cin >> y1;
    cout << "Give length of one side: ";
    cin >> length;
    cout << "Give rotation in clockwise: ";
    double angle =  45; // Angle in degrees
    cin >> angle;
    double radians = angle * M_PI / 180.0;


    x2 = x1+length;
    y2 = y1;
    x3 = x1+length;
    y3 = y1+length;
    x4 = x1;
    y4 = y1+length;

    initwindow(700, 500, "Rotation", 50,80);
    line(x1, y1, x2, y2);
    line(x1, y1, x4, y4);
    line(x2, y2, x3, y3);
    line(x4, y4, x3, y3);

     // Rotate the first arm
    xr = x1;
    yr = y1;
    x = x2;
    y = y2;

    float rotatedX = xr + (x - xr) * cos(radians) - (y - yr) * sin(radians);
    float rotatedY = yr + (x - xr) * sin(radians) + (y - yr) * cos(radians);

    setcolor(YELLOW);
    line(xr, yr, rotatedX, rotatedY);

    // Rotate the second arm
    x2 = rotatedX;
    y2 = rotatedY;
    x = x3;
    y = y3;

    rotatedX = xr + (x - xr) * cos(radians) - (y - yr) * sin(radians);
    rotatedY = yr + (x - xr) * sin(radians) + (y - yr) * cos(radians);

    setcolor(YELLOW);
    line(x2, y2, rotatedX, rotatedY);

    // Rotate the third arm
    x3 = rotatedX;
    y3 = rotatedY;
    x = x4;
    y = y4;

    rotatedX = xr + (x - xr) * cos(radians) - (y - yr) * sin(radians);
    rotatedY = yr + (x - xr) * sin(radians) + (y - yr) * cos(radians);
    line(x3, y3, rotatedX, rotatedY);

    //Print the fourth arm
    line(x1, y1, rotatedX, rotatedY);



    getch();
    return 0;
}


