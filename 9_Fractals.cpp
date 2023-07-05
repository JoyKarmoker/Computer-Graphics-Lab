#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
void koch(int x1, int y1, int x2, int y2, int it)
{
    float angle = 60*3.1416/180; //60 deg
    int x3 = (2*x1+x2)/3;
    int y3 = (2*y1+y2)/3;

    int x4 = (x1+2*x2)/3;
    int y4 = (y1+2*y2)/3;
//    int distx=sqrt( (x4-x3)*(x4-x3) + (y4-y3)*(y4-y3) );
//    int x=distx*cos(angle);
//    int y=distx*sin(angle);
    int x = x3 + (x4-x3)*cos(angle)+(y4-y3)*sin(angle);
    int y = y3 - (x4-x3)*sin(angle)+(y4-y3)*cos(angle);

    if(it > 1)
    {
        koch(x1, y1, x3, y3, it-1);
        koch(x3, y3, x, y, it-1);
        koch(x, y, x4, y4, it-1);
        koch(x4, y4, x2, y2, it-1);
    }
    else
    {

        line(x1, y1, x3, y3);
        line(x3, y3, x, y);
        line(x, y, x4, y4);
        line(x4, y4, x2, y2);
    }
}

int main(void)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int gen = 3;
    koch(50, 200, 250, 200, gen);
    getch();
    return 0;
}
