/*************************************************************************
                           Polyline  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Réalisation de la classe <Polyline> (fichier Polyline) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Polyline.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Polyline::Move ( vector<long> dXY )
// Algorithme :
//
{   for (unsigned int i = 0; i < points.size(); i++)
	{
		points.at(i).Move(dXY.at(0), dXY.at(1));
	}
} //----- Fin de Méthode

bool Polyline::InsideOf (Point point1, Point point2)
// Algorithme :
//
{
	vector<Point>::iterator it;

	long minX, maxX, minY, maxY;
    if(point1.GetX() > point2.GetX())
    {   minX = point2.GetX();
        maxX = point1.GetX();
    }
    else
    {   minX = point1.GetX();
        maxX = point2.GetX();
    }
    if(point1.GetY() > point2.GetY())
    {   minY = point2.GetY();
        maxY = point1.GetY();
    }
    else
    {   minY = point1.GetY();
        maxY = point2.GetY();
    }

	for (it = points.begin(); it != points.end(); ++it)
	{
		if(minX > it->GetX() || maxX < it->GetX() || minY > it->GetY() || maxY < it->GetY())
        {   return false;
        }
	}
	return true;
} //----- Fin de Méthode

string Polyline::Command ()
// Algorithme :
//
{
	stringstream strstream;
	string line;

	strstream << "PL " << name;

	for (unsigned int i = 0; i < points.size(); i ++)
	{   strstream << " " << points.at(i).GetX() << " " << points.at(i).GetY();
	}
	line = strstream.str();

	return line;
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Polyline::Polyline ( const Polyline & unPolyline ) : Shape(unPolyline), points(unPolyline.points)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polyline>" << endl;
#endif
} //----- Fin de Polyline (constructeur de copie)

Polyline::Polyline (string nom, vector<long> & data)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Polyline>" << endl;
#endif

	name = nom;

	for (unsigned int i = 0; i < data.size(); i += 2)
	{   Point point(data.at(i),data.at(i+1));
	    points.push_back(point);
	}
} //----- Fin de Polyline

Polyline::Polyline () : Shape(), points()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Polyline>" << endl;
#endif
} //----- Fin de Polyline


Polyline::~Polyline ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Polyline>" << endl;
#endif
} //----- Fin de ~Polyline


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
