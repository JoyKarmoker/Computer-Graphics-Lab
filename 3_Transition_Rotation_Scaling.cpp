#include<graphics.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    //Transition;
    /*
    int x1 = 50;
    int y1 = 450;
    int x2 = 250;
    int y2 = 450;
    int x3 = (x1+x2) /2 ;
    int y3 = 250;
    int transitionx = 250;
    int transitiony = -200;

    cout << "Give origin x value: ";
    cin >> x1;
    cout << "Give origin y value: ";
    cin >> y1;

    cout << "Give transition x value: ";
    cin >> transitionx;
    cout << "Give transition y value: ";
    cin >> transitiony;

    initwindow(700, 500, "Transition Rotation Scaling", 50,80);
    x2 = x1+200;
    y2 = y1;
    x3 = (x1+x2)/2;
    y3 = y1-200;
    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);
    setfillstyle(SOLID_FILL, RED);
    floodfill((x1+1), (y1-1), RED);

    initwindow(700, 500, "Transition Rotation Scaling", 800,80);
    x1 = x1+transitionx;
    y1 = y1 + transitiony;
    x2 = x2+transitionx;
    y2 = y2+transitiony;
    x3 = x3+transitionx;
    y3 = y3+transitiony;

    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x1, y1, x3, y3);
    line(x2, y2, x3, y3);
    setfillstyle(SOLID_FILL, RED);
    floodfill((x1+1), (y1-1), RED);
    */

    //Scalling
    float  x1, y1, x2, y2, x3, y3, x4, y4, length, sx, sy;
    cout << "Give origin x value: ";
    cin >> x1;
    cout << "Give origin y value: ";
    cin >> y1;
    cout << "Give length of one side: ";
    cin >> length;

    cout << "Give Sx: ";
    cin >> sx;
    cout << "Give Sy: ";
    cin >> sy;

    x2 = x1+length;
    y2 = y1;
    x3 = x1+length;
    y3 = y1+length;
    x4 = x1;
    y4 = y1+length;

    initwindow(700, 500, "Transition Rotation Scaling", 50,80);
    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x1, y1, x4, y4);
    line(x2, y2, x3, y3);
    line(x4, y4, x3, y3);
    setfillstyle(SOLID_FILL, RED);
    floodfill((x1+1), (y1+1), RED);

    /*Scaled and repositioned;
    Scaling factors with valuse less than 1 move objects
    Values greater than 1 move coordinate positions farther from origin*/
    /*
    x1 = x1*sx;
    y1 = y1*sy;
    x2 = x2*sx;
    y2 = y2*sy;
    x3 = x3*sx;
    y3 = y3*sy;
    x4 = x4*sx;
    y4 = y4*sy;
    initwindow(700, 500, "Transition Rotation Scaling", 800,80);
    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x1, y1, x4, y4);
    line(x2, y2, x3, y3);
    line(x4, y4, x3, y3);
    setfillstyle(SOLID_FILL, RED);
    floodfill((x1+1), (y1+1), RED);
    */

    //Fixed Point Scaling
    /* Taking The center of square as fixed point xf, yf*/
    float xf = (x1+x2)/2.0;
    float yf = (y1+y4) / 2.0;

    /*
    For Finding the vertex the formula is x' = x*sx + xf*(1-sx), y' = y*sy + yf*(1-sy);
    Here xf*(1-sx) are fixed for all points so we put in the varaible dx
    also yf*(1-sy) are fixed for all points so we put in the varaible dy
    */

    float dx =  xf*(1.0-sx);
    float dy = yf*(1.0-sy);
    x1 = x1*sx + dx;
    y1 = y1*sy + dy;
    x2 = x2*sx+dx;
    y2 = y2*sy+dy;
    x3 = x3*sx+dx;
    y3 = y3*sy+dy;
    x4 = x4*sx+dx;
    y4 = y4*sy+dy;
    initwindow(700, 500, "Transition Rotation Scaling", 800,80);
    setcolor(RED);
    line(x1, y1, x2, y2);
    line(x1, y1, x4, y4);
    line(x2, y2, x3, y3);
    line(x4, y4, x3, y3);
    setfillstyle(SOLID_FILL, RED);
    floodfill((x1+1), (y1+1), RED);



    getch();
    return 0;
}
