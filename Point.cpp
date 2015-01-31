/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier Point) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Point::Move( long dX, long dY )
// Algorithme :
//
{
	x=x+dX;
	y=y+dY;
} //----- Fin de Méthode

long Point::GetX ( )
// Algorithme :
//
{
	return x;
} //----- Fin de Méthode

long Point::GetY ( )
// Algorithme :
//
{
	return y;
} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & unPoint )
// Algorithme :
//
{
    x = unPoint.x;
    y = unPoint.y;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
} //----- Fin de Point (constructeur de copie)

Point::Point () : x(0), y(0)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point

Point::Point (long posX, long posY ) : x(posX), y(posY)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
