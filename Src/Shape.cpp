 /*************************************************************************
                           Shape  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Réalisation de la classe <Shape> (fichier Shape) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Shape.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
string Shape::GetName()
// Algorithme :
//
{
	return name;
} //----- Fin de Méthode

vector<string>  & Shape::GetSelections()
{
    return inSelection;
}

void Shape::addSelection(string selection)
// Algorithme :
//
{   inSelection.push_back(selection);
} //----- Fin de Méthode

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

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
