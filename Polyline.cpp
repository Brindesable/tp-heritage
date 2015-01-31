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
	bool inside = true;

	for (it = points.begin(); it != points.end() && inside; ++it)
	{
		if((point1.GetX()<=(*it).GetX() && (*it).GetX()<=point2.GetX())||(point2.GetX()<=(*it).GetX() && (*it).GetX()<=point1.GetX()))
		{
			if((point1.GetY()<=(*it).GetY() && (*it).GetY()<=point2.GetY())||(point2.GetX()<=(*it).GetY() && (*it).GetY()<=point1.GetY()))
			{
			}else{
				inside=false;
			}
		}else{
			inside=false;
		}
	}
	return inside;
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
