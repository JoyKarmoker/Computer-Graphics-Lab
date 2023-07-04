#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<bitset>
using namespace std;
pair<int, int> firstendpoint = {-1,-1};

pair<int, int> cohen_sutherland(int xa, int ya, int xb, int yb, int xmin, int xmax, int ymin, int ymax, int lastx, int lasty)
{

    double m;
    pair<int, int> mp;
    bitset<4> pointa, pointb;
    string tempa="0000", tempb="0000";

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
        setcolor(RED);
        if(lastx !=-1  && lasty!= -1)
        {
                 line(lastx, lasty, xa, ya);
        }

        if(firstendpoint.first== -1 && firstendpoint.second == -1)
        {
            firstendpoint.first = xa;
            firstendpoint.second = ya;
        }

        line(xa, ya, xb, yb);

        mp.first = xb;
        mp.second = yb;

        return mp;
    }
    else if (result != comparison)
    {
        cout << "The Line is completely outside" <<endl;
        mp.first = lastx;
        mp.second = lasty;
        return mp;
    }
    else
    {
        cout << "The line is partialy inside" << endl;
        //line(xa, ya, xb, yb);

        // Perform clipping
        /*find slope m*/
        m = ((yb-ya)*1.0) / ((xb - xa)*1.0) ;

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
        //cout << "xa: " << xa << " ya: " << ya << endl;
        if(lastx !=-1  && lasty!= -1)
        {
                 line(lastx, lasty, xa, ya);
        }

        if(firstendpoint.first== -1 && firstendpoint.second == -1)
        {
            firstendpoint.first = xa;
            firstendpoint.second = ya;
        }
        line(xa, ya, xb, yb);

        mp.first = xb;
        mp.second = yb;

        return mp;
    }
}



int main()
{
    int number_of_edge, number_of_vertex;
    cout << "Give the number of edges in polygon: ";
    cin >> number_of_edge;
    number_of_vertex = number_of_edge;
    pair<int, int> vertex[ number_of_vertex ];
    pair<int, int> endpoint = {-1,-1};

    cout << "Give " << number_of_vertex  << " Vertices : " << endl;;
    char c = 'A';
    for(int i=0; i<number_of_vertex; i++)
    {
        cout << "Give " << c++ << " : ";
        cin >> vertex[i].first >> vertex[i].second;
    }

    for(int i=0; i<number_of_vertex; i++)
    {
        cout <<  vertex[i].first <<" " <<vertex[i].second << endl;
    }


    int xmax, xmin, ymax, ymin;
    cout << "Give xmin, xmax, ymin, ymax: ";
    cin >> xmin >> xmax >> ymin >> ymax;

    initwindow(1000, 800, "Cohen Sutherland Line Clipping", 300, 50);


    line(xmin, ymin, xmax, ymin);
    line(xmin,ymin, xmin, ymax);
    line(xmax, ymin, xmax, ymax);
    line(xmin, ymax, xmax, ymax);

    for(int i=0; i<number_of_vertex-1; i++)
    {
        line(vertex[i].first, vertex[i].second, vertex[i+1].first, vertex[i+1].second);
    }

    line(vertex[number_of_vertex-1].first, vertex[number_of_vertex-1].second, vertex[0].first, vertex[0].second);

    for(int i=0; i<number_of_vertex-1; i++)
    {
        endpoint = cohen_sutherland(vertex[i].first, vertex[i].second, vertex[i+1].first, vertex[i+1].second, xmin, xmax, ymin, ymax, endpoint.first, endpoint.second);
    }

    endpoint = cohen_sutherland(vertex[number_of_vertex-1].first, vertex[number_of_vertex-1].second, vertex[0].first, vertex[0].second, xmin, xmax, ymin, ymax, endpoint.first, endpoint.second);
    line(endpoint.first, endpoint.second, firstendpoint.first, firstendpoint.second);

    getch();
    closegraph();
    return 0;
}
/*
5
400 50
400 450
950 450
400 750
50 450
100
900
100
700

5
50 10
400 450
950 450
400 750
50 450
100
900
100
700

5
500 10
400 450
40 50
400 50
50 450
100
900
100
700

*/
