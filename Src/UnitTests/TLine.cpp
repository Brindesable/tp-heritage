#include "TLine.h"
#include "../Line.h"

bool TLine::UnitTest1()
{
    vector<long> points;
    points.push_back(-10);
    points.push_back(10);
    points.push_back(0);
    points.push_back(-20);

    Line l("l", points);

    if(l.Command() == "L l -10 10 0 -20")
    {   return true;
    }
    else
    {   return false;
    }
}
