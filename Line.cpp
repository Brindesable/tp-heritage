/*************************************************************************
                           Line  -  description
                             -------------------
    d�but                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- R�alisation de la classe <Line> (fichier Line) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Line.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
string Line::Command ()
// Algorithme :
//
{
	stringstream strstream;
	string line;

	strstream<<"L "<<name;

	for (unsigned int i = 0; i < points.size(); i ++)
	{   strstream << " " << points.at(i).GetX() << " " << points.at(i).GetY();
	}
	line = strstream.str();

	return line;
} //----- Fin de M�thode

//-------------------------------------------- Constructeurs - destructeur
Line::Line ( const Line & unLine ) : Polyline(unLine)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Line>" << endl;
#endif
} //----- Fin de Line (constructeur de copie)

Line::Line (string nom, vector<long> & data) : Polyline(nom, data)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Line>" << endl;
#endif
} //----- Fin de Line

Line::Line()
// Algorithme :
//
{
    Polyline();
#ifdef MAP
    cout << "Appel au constructeur de <Line>" << endl;
#endif
} //----- Fin de Line


Line::~Line ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Line>" << endl;
#endif
} //----- Fin de ~Line


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
