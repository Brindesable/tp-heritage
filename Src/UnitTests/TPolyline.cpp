#include "TPolyline.h"
#include "../Line.h"

bool TPolyline::UnitTest1()
{
    vector<long> points;
    points.push_back(-10);
    points.push_back(10);
    points.push_back(0);
    points.push_back(-20);
    points.push_back(0);
    points.push_back(0);
    points.push_back(30);
    points.push_back(40);

    Polyline l("pl", points);

    vector<long> delta;
    delta.push_back(-10);
    delta.push_back(10);

    l.Move(delta);

    if(l.Command() == "PL pl -20 20 -10 -10 -10 10 20 50")
    {   return true;
    }
    else
    {   return false;
    }
}

bool TPolyline::UnitTest2()
{
    vector<long> points;
    points.push_back(-10);
    points.push_back(10);
    points.push_back(0);
    points.push_back(-20);
    points.push_back(0);
    points.push_back(0);
    points.push_back(30);
    points.push_back(40);

    Point point1(-10, 40);
    Point point2(30, -20);

    Point point3(-10, 39);
    Point point4(30, -20);

    Polyline l("pl", points);

    if(l.InsideOf(point1, point2) && !l.InsideOf(point3, point4))
    {   return true;
    }
    else
    {   return false;
    }
}

