#include<stdio.h>
#include<graphics.h>
#include<iostream>
int main()
{

    int gd, gm;
    detectgraph(&gd, &gm);
    initgraph(&gd, &gm, "C;\\TURBOC3\\BG1");

    setcolor(GREEN);
    rectangle(50,50, 220,150);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(51,51, GREEN);

    setcolor(WHITE);
    rectangle(40,40, 50,300);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(41,41, WHITE);

    setcolor(RED);
    circle(126.5, 100, 34);
    setfillstyle(SOLID_FILL, RED);
    floodfill(126.5, 100, RED);

    getch();
    return 0;
}
