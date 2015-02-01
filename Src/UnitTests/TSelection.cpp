#include "TSelection.h"
#include "../Selection.h"
#include "../Circle.h"
#include "../Rectangle.h"


#include <iostream>
using namespace std;

bool TSelection::UnitTest1()
{
    vector<long> pointsShape1;
    pointsShape1.push_back(-10);
    pointsShape1.push_back(10);
    pointsShape1.push_back(0);
    pointsShape1.push_back(-20);

    vector<long> pointsShape2;
    pointsShape2.push_back(-10);
    pointsShape2.push_back(10);
    pointsShape2.push_back(20);

    vector<long> delta;
    delta.push_back(-10);
    delta.push_back(10);

    vector<string> history;

    Shape * shape1 = new Rectangle("r", pointsShape1);
    Shape * shape2 = new Circle("c", pointsShape2);

    Selection sel;

    sel.AddShape(shape1);
    sel.AddShape(shape2);


    sel.Move(delta, history);

    if(sel.GetNbShapesInside() != 2)
    {   return false;
    }
    if(history[0] != "MOVE"
       || (history[1] != "MOVE r -10 10" && history[2] != "MOVE r -10 10")
       || (history[1] != "MOVE c -10 10" && history[2] != "MOVE c -10 10"))
    {   return false;
    }

    return true;
}
