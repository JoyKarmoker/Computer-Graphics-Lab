#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double x[4], y[4], t, putx, puty;

    cout << "Give four control points: ";
    for(int i=0; i<4; i++)
    {
        cout << "Point " << (i+1) << " (x, y): ";
        cin >> x[i] >> y[i];
        cout << endl;
    }

    initwindow(1000, 800, "Beizier Curve", 300, 50);
    for(int i=0; i<4; i++)
    {
        putpixel(x[i], y[i], RED);
    }

    for(t=0.0; t<=1.0; t = t + 0.00001)
    {
        putx = pow((1-t), 3) * x[0] + 3*t*pow(1-t, 2) * x[1] + 3*pow(t, 2) * (1-t)*x[2] + pow(t,3) * x[3];
        puty = pow(1-t, 3) * y[0]+ 3*t*pow(1-t, 2)*y[1] + 3 * pow(t, 2) * (1-t) * y[2] + pow(t, 3) * y[3];
         putpixel(putx, puty, GREEN);
    }

    getch();
    closegraph();
    return 0;
}

/*
100 300
200 100
300 500
400 300
*/
