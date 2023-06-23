#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

void draw(char c, int x1, int y1, int x2, int y2)
{

    if(c=='s')
    {
        readimagefile("shakib.jpg", x1, y1, x2, y2);
    }

    else if(c=='l')
    {
        readimagefile("liton.jpg", x1, y1, x2, y2);
    }

    else if(c=='m')
    {
        readimagefile("mushi.jpg", x1, y1, x2, y2);
    }

    else
    {
        cout << "Wrong Input";
    }

    return;
}

void drawshape(char c, int x1, int y1, int x2, int y2)
{

    if(c=='t')
    {
        setcolor(RED);
        float middle = (x1+x2)/2.0;
        line(x1, y2, x2, y2);
        line(x1, y2, middle, y1);
        line(x2, y2,  middle, y1);

        setfillstyle(SOLID_FILL, RED);
        floodfill(middle, (y2-1), RED);
    }

    else if(c=='c')
    {
        setcolor(GREEN);
        float centerx = (x1+x2) / 2.0;
        float centery = (y1+y2)/2.0;
        float radius = (x2-x1) /2.0;

        circle(centerx, centery, radius);
        setfillstyle(SOLID_FILL, GREEN);
        floodfill(centerx, centery, GREEN);
    }

    else if(c=='s')
    {
        setcolor(BLUE);
        rectangle(x1, y1, x2, y2);
        setfillstyle(SOLID_FILL, BLUE);
        floodfill((x1+1), (y1+1), BLUE);
    }

    else
    {
        cout << "Wrong Input";
    }

    return;
}

int main()
{

    string order = "tcs";
    cout << "Give the order" << endl;
    cin >> order;
    int length = order.size();

    if(length !=  3)
    {
        cout << "wrong input" << endl;
        return 0;
    }

    initwindow(1000, 750, "Hidden Surface Elimination", 300, 20);

    /*Using Images*/
    /*
     int x1 = 350, y1=50, x2=550, y2=250;
    for(int i=0; i<3; i++)
    {

        draw(order[i], x1, y1, x2, y2);
        x1 = x1-100;
        y1 = y1+50;
        x2 = x1+200;
        y2 = y1+200;
    }
    */

    /*For Objects*/
     int x1 = 100, y1=50, x2=300, y2=250;

    for(int i=0; i<3;i++)
    {
        drawshape(order[i], x1, y1, x2, y2);
        x1 = x1 + 70;
        y1 = y1+70;
        x2 = x2+70;
        y2 = y2+70;
    }

    getch();
    return 0;
}

