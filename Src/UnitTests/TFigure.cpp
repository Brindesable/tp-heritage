#include "../Figure.h"
#include "TFigure.h"

#include <iostream>
#include <fstream>
using namespace std;

bool TFigure::UnitTest1()
{
    vector<long> pointsRect;
    pointsRect.push_back(0);
    pointsRect.push_back(0);
    pointsRect.push_back(20);
    pointsRect.push_back(20);

    vector<long> pointsCirc;
    pointsCirc.push_back(0);
    pointsCirc.push_back(0);
    pointsCirc.push_back(20);

    vector<long> pointsLine;
    pointsLine.push_back(0);
    pointsLine.push_back(0);
    pointsLine.push_back(20);
    pointsLine.push_back(20);

    vector<long> pointsPoly;
    pointsPoly.push_back(0);
    pointsPoly.push_back(0);
    pointsPoly.push_back(20);
    pointsPoly.push_back(20);
    pointsPoly.push_back(0);
    pointsPoly.push_back(20);

    Figure fig;
    fig.AddCircle("c", pointsCirc, true);
    fig.AddRectangle("r", pointsRect, true);
    fig.AddLine("l", pointsLine, true);
    fig.AddPolyline("pl", pointsPoly, true);

    if(fig.List() != "C c 0 0 20\r\nL l 0 0 20 20\r\nPL pl 0 0 20 20 0 20\r\nR r 0 0 20 20\r\n")
    {   return false;
    }

    fig.Save("test.txt");

    ifstream fichier ("test.txt", ios::in);// on ouvre en lecture
    if(fichier)  // si l'ouverture a fonctionné
	{
		string line, content;  // déclaration d'une chaîne qui contiEndRa la ligne lue
		while(getline(fichier, line))
		{   content += line;
            content += "\r\n";
		}
		fichier.close(); //Quand on a tout finit on ferme le fichier

		if(content != "C c 0 0 20\r\nL l 0 0 20 20\r\nPL pl 0 0 20 20 0 20\r\nR r 0 0 20 20\r\n")
        {   return false;
        }
	}
	else
	{   return false;
	}

    return true;
}

bool TFigure::UnitTest2()
{
    vector<long> pointsRect;
    pointsRect.push_back(0);
    pointsRect.push_back(0);
    pointsRect.push_back(20);
    pointsRect.push_back(20);

    vector<long> pointsCirc;
    pointsCirc.push_back(0);
    pointsCirc.push_back(0);
    pointsCirc.push_back(20);

    vector<long> pointsLine;
    pointsLine.push_back(0);
    pointsLine.push_back(0);
    pointsLine.push_back(20);
    pointsLine.push_back(20);

    vector<long> pointsPoly;
    pointsPoly.push_back(0);
    pointsPoly.push_back(0);
    pointsPoly.push_back(20);
    pointsPoly.push_back(20);
    pointsPoly.push_back(0);
    pointsPoly.push_back(20);

    Figure fig;
    fig.AddCircle("c", pointsCirc, true);
    fig.AddRectangle("r", pointsRect, true);
    fig.AddLine("l", pointsLine, true);
    fig.AddPolyline("pl", pointsPoly, true);

    int nbObjectsDeleted;
    vector<string> shapesToDel;
    shapesToDel.push_back("l");

    fig.Delete(shapesToDel, true, nbObjectsDeleted);

    if(nbObjectsDeleted != 1 || fig.List() != "C c 0 0 20\r\nPL pl 0 0 20 20 0 20\r\nR r 0 0 20 20\r\n")
    {   return false;
    }

    fig.Clear(true);

    if(fig.List() != "#anything created yet\r\n")
    {   return false;
    }

    return true;
}

