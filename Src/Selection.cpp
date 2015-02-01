/*************************************************************************
                           Selection  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Réalisation de la classe <Selection> (fichier Selection) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Selection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Selection::AddShape (Shape * forme)
// Algorithme :
//
{   shapes.insert(forme);
} //----- Fin de Méthode

void Selection::RemoveShape (Shape * forme)
// Algorithme :
//
{   shapes.erase(forme);
}

void Selection::Move( vector<long> dXY , vector<string> & lineCommand)
// Algorithme :
//
{   set<Shape *>::iterator is;
    string line;

    line = "MOVE";
    lineCommand.push_back(line);

    for(is = shapes.begin(); is != shapes.end(); ++is)
    {   //move shape
        (*is)->Move(dXY);
        //generation d'historique
        stringstream strstream;
        strstream<<"MOVE "<<(*is)->GetName()<<" "<<dXY.at(0)<<" "<<dXY.at(1);
        line = strstream.str();
        lineCommand.push_back(line);
    }
} //----- Fin de Méthode


set<Shape*> & Selection::GetShapesInside()
// Algorithme :
//
{   return shapes;
}//----- Fin de Méthode

int Selection::GetNbShapesInside()
// Algorithme :
//
{   return shapes.size();
}

//-------------------------------------------- Constructeurs - destructeur
Selection::Selection ( const Selection & unSelection ) : shapes(unSelection.shapes)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Selection>" << endl;
#endif
} //----- Fin de Selection (constructeur de copie)

Selection::Selection ( ) : shapes()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Selection>" << endl;
#endif
} //----- Fin de Selection


Selection::~Selection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Selection>" << endl;
#endif
} //----- Fin de ~Selection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
