#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<bitset>
using namespace std;
int main()
{

    double xmax, xmin, ymax, ymin, x1, y1, x2, y2, x3, y3, x4, y4, xa, ya, xb, yb, m;
    bitset<4> pointa, pointb;
    string tempa="0000", tempb="0000";

    cout << "Give xmin, xmax, ymin, ymax: ";
    cin >> xmin >> xmax >> ymin >> ymax;

    cout << "Give first end of the line (xa, ya): ";
    cin >> xa >> ya;
    cout << "Give second end of the line (xb, yb): ";
    cin >> xb >> yb;


    x1 = xmin;
    y1 = ymin;
    x2 = xmax;
    y2 = ymin;
    x3 = xmax;
    y3 = ymax;
    x4 = xmin;
    y4 = ymax;
    initwindow(1000, 800, "Cohen Sutherland Line Clipping", 300, 50);


    line(x1, y1, x2, y2);
    line(x1, y1, x4, y4);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);

    if(ya < ymin)
    {
        tempa[0] = '1';
    }
    if(ya>ymax)
    {
        tempa[1] = '1';
    }
    if(xa>xmax)
    {
        tempa[2] = '1';
    }
    if(xa<xmin)
    {
        tempa[3] = '1';
    }

    pointa = bitset<4> (tempa);
    //cout << "Point a: " << pointa;

    if(yb < ymin)
    {
        tempb[0] = '1';
    }
    if(yb>ymax)
    {
        tempb[1] = '1';
    }
    if(xb>xmax)
    {
        tempb[2] = '1';
    }
    if(xb<xmin)
    {
        tempb[3] = '1';
    }
    pointb = bitset<4> (tempb);
    //cout << "Point b: " << pointb;

    bitset<4> result = pointa & pointb;
    bitset<4> comparison("0000");
    if(pointa == comparison && pointb == comparison)
    {
        cout << "The Line is completely inside" <<endl;
        line(xa, ya, xb, yb);
    }
    else if (result != comparison)
    {
        cout << "The Line is completely outside" <<endl;
        line(xa, ya, xb, yb);
    }
    else
    {
        cout << "The line is partialy inside" << endl;
        setcolor(WHITE);
        line(xa, ya, xb, yb);

        // Perform clipping
        /*find slope m*/
        m = (yb-ya) / (xb - xa);

        //For point a
        /*If point a is in top*/
        if(ya < ymin)
        {
            xa = xb + (ymin - yb) / m;
            ya = ymin;
            cout << "Top xa: " << xa << " ya: " << ya << endl;
        }
        //if point a is in bottom
        else if(ya > ymax)
        {
            cout << "Bottom\n";
            xa = xb + (ymax-yb) / m;
            ya = ymax;
        }

        //if point a is in right
        if(xa > xmax )
        {
            xa = xmax;
            ya = yb + (xmax - xb) * m;
            cout << "Right\n";
        }
        //if point a is in left
        else if(xa<xmin)
        {
            cout << "left\n";
            xa = xmin;
            ya = yb + (xmin - xb) * m;
        }


        //For Point b
        //If point b is in top
        if(yb<ymin)
        {
            xb = xa + (ymin-ya)/m;
            yb = ymin;
        }
        //if point b is below;
        else if(yb>ymax)
        {
            xb = xa + (ymax-ya)/m;
            yb = ymax;
        }

        //if point a is in left
        if(xb < xmin)
        {
            xb = xmin;
            yb = ya + (xmin-xa)*m;

        }

        else if(xb > xmax)
        {
            xb = xmax;
            yb = ya + (xmax - xa) * m;
        }


        setcolor(RED);
        cout << "xa: " << xa << " ya: " << ya << endl;
        line(xa, ya, xb, yb);

    }


    getch();
    closegraph();
    return 0;
}

/*
Top Left:
100
900
100
700
50 50
400 600

Top:
100
900
100
700
450 50
400 600

Top Right:
100
900
100
700
950 80
400 600


Right:
100
900
100
700
950 400
400 600

Bottom Right:
100
900
100
700
950 750
400 600

Bottom:
100
900
100
700
450 750
400 600

Bottom left:
100
900
100
700
50 750
400 600

left:
100
900
100
700
50 400
400 600

point b top:
100
900
100 700
400 400
500 50

point b below:
100
900
100 700
400 400
500 850

point b left:
100
900
100 700
400 400
50 500

point b right:
100
900
100 700
400 400
950 500

point b top left:
100
900
100
700
400 400
50 40

point b top right:
100
900
100
700
400 400
950 40

point b below right:
100
900
100
700
50 50
950 740

point b below left:
100
900
100
700
400 50
50 740

*/



