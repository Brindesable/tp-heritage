 /*************************************************************************
                           Shape  -  description
                             -------------------
    d�but                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- R�alisation de la classe <Shape> (fichier Shape) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Shape.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
string Shape::GetName()
// Algorithme :
//
{
	return name;
} //----- Fin de M�thode

vector<string>  & Shape::GetSelections()
{
    return inSelection;
}

void Shape::addSelection(string selection)
// Algorithme :
//
{   inSelection.push_back(selection);
} //----- Fin de M�thode

//-------------------------------------------- Constructeurs - destructeur
Shape::Shape ( const Shape & unShape ) : name(unShape.name), inSelection(unShape.inSelection)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Shape>" << endl;
#endif
} //----- Fin de Shape (constructeur de copie)


Shape::Shape ( ) : name(), inSelection()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Shape>" << endl;
#endif
} //----- Fin de Shape


Shape::~Shape ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Shape>" << endl;
#endif
} //----- Fin de ~Shape


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
