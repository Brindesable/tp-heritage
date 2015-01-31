/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Réalisation de la classe <Rectangle> (fichier Rectangle) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

string Rectangle::Command ()
// Algorithme :
//
{
	stringstream strstream;
	string line;

	strstream<<"R "<<name;

    //on ne prend que les deux premiers points
	for (int i = 0; i < 2; i ++)
	{   strstream << " " << points.at(i).GetX() << " " << points.at(i).GetY();
	}
	line = strstream.str();

	return line;
} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( const Rectangle & unRectangle ) : Polyline(unRectangle)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle (constructeur de copie)


Rectangle::Rectangle (string nom, vector<long> & data) : Polyline(nom, data)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
    //creation des deux autres points du rectangle
    Point point3(points.at(0).GetX(), points.at(1).GetY());
    Point point4(points.at(1).GetX(), points.at(0).GetY());
    points.push_back(point3);
    points.push_back(point4);
} //----- Fin de Rectangle


Rectangle::Rectangle () : Polyline()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle


Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
