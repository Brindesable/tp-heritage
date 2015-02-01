#include "TRectangle.h"
#include "../Rectangle.h"
#include <vector>

bool TRectangle::UnitTest1()
{
    vector<long> points;
    points.push_back(-10);
    points.push_back(10);
    points.push_back(0);
    points.push_back(-20);

    Rectangle r("r", points);

    if(r.Command() == "R r -10 10 0 -20")
    {   return true;
    }
    else
    {   return false;
    }
}
