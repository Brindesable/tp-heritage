/*************************************************************************
                           Circle  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Réalisation de la classe <Circle> (fichier Circle) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Circle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Circle::Move ( vector<long> dXY )
// Algorithme :
//
{
	center.Move(dXY.at(0), dXY.at(1));
} //----- Fin de Méthode

bool Circle::InsideOf (Point point1, Point point2)
// Algorithme :
//
{
	if((point1.GetX()<=center.GetX()-radius && center.GetX()-radius<=point2.GetX())||(point2.GetX()<=center.GetX()-radius && center.GetX()-radius<=point1.GetX()))
	{
		if((point1.GetY()<=center.GetX()+radius && center.GetX()+radius<=point2.GetX())||(point2.GetX()<=center.GetX()+radius && center.GetX()-radius<=point1.GetX()))
		{
			if((point1.GetY()<=center.GetY()-radius && center.GetY()-radius<=point2.GetY())||(point2.GetY()<=center.GetY()-radius && center.GetY()-radius<=point1.GetY()))
			{
				if((point1.GetY()<=center.GetY()+radius && center.GetY()+radius<=point2.GetY())||(point2.GetY()<=center.GetY()+radius && center.GetY()-radius<=point1.GetY()))
				{
					return true;
				}else{
					return false;
				}
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
} //----- Fin de Méthode

string Circle::Command ()
// Algorithme :
//
{
    string line;
	stringstream strstream;

	strstream<<"C "<<name<<" "<<center.GetX()<<" "<<center.GetY()<<" "<<radius;
	line = strstream.str();

	return line;
} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Circle::Circle ( const Circle & unCircle )
// Algorithme :
//
{
    name = unCircle.name;
    center = unCircle.center;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Circle>" << endl;
#endif
} //----- Fin de Circle (constructeur de copie)

Circle::Circle () : Shape(), radius(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Circle>" << endl;
#endif
} //----- Fin de Circle

Circle::Circle (string nom, vector<long> & data )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Circle>" << endl;
#endif
	name=nom;
	radius=data.at(2);
	center=Point(data.at(0),data.at(1));
} //----- Fin de Circle


Circle::~Circle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Circle>" << endl;
#endif
} //----- Fin de ~Circle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
