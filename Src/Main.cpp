#include "Application.h"

#define TEST
#ifndef TEST

int main()
{
    Application app;
    app.Launch();

    return 0;
}

#endif
#ifdef TEST

#include <iostream>
#include "UnitTests/TCircle.h"
#include "UnitTests/TLine.h"
#include "UnitTests/TPolyline.h"
#include "UnitTests/TRectangle.h"
#include "UnitTests/TSelection.h"
#include "UnitTests/TFigure.h"

using namespace std;

int main()
{
    cout << "----- Test Circle -----" << endl;
    cout << "Test 1 : " << (TCircle::UnitTest1() ? "OK" : "KO") << endl;
    cout << "Test 2 : " << (TCircle::UnitTest2() ? "OK" : "KO") << endl;
    cout << "----- Test PolyLine -----" << endl;
    cout << "Test 1 : " << (TPolyline::UnitTest1() ? "OK" : "KO") << endl;
    cout << "Test 2 : " << (TPolyline::UnitTest2() ? "OK" : "KO") << endl;
    cout << "----- Test Line -----" << endl;
    cout << "Test 1 : " << (TLine::UnitTest1() ? "OK" : "KO") << endl;
    cout << "----- Test Rectangle -----" << endl;
    cout << "Test 1 : " << (TRectangle::UnitTest1() ? "OK" : "KO") << endl;
    cout << "----- Test Selection -----" << endl;
    cout << "Test 1 : " << (TSelection::UnitTest1() ? "OK" : "KO") << endl;
    cout << "----- Test Figure -----" << endl;
    cout << "Test 1 : " << (TFigure::UnitTest1() ? "OK" : "KO") << endl;

    return 0;
}

#endif // TEST
