#include "../Circle.h"
#include "../Point.h"
#include "TCircle.h"

bool TCircle::UnitTest1()
{
    vector<long> points;
    points.push_back(20);
    points.push_back(20);
    points.push_back(20);

    vector<long> delta;
    delta.push_back(-10);
    delta.push_back(10);

    Circle c("c1", points);

    c.Move(delta);

    if(c.Command() == "C c1 10 30 20")
    {   return true;
    }
    else
    {   return false;
    }
}

bool TCircle::UnitTest2()
{
    vector<long> points;
    points.push_back(20);
    points.push_back(20);
    points.push_back(20);
    Circle c("c1", points);

    Point point1(0, 0);
    Point point2(40, 40);
    Point point3(0, 0);
    Point point4(40, 39);

    if(c.InsideOf(point1, point2) && !c.InsideOf(point3, point4))
    {   return true;
    }
    else
    {   return false;
    }
}

