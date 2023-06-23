#include<graphics.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
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


    getch();
    return 0;
}

