/*************************************************************************
                           Shape  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Interface de la classe <Shape> (fichier Shape) ------
#if ! defined ( SHAPE_H )
#define SHAPE_H

using namespace std;
#include <iostream>
#include <string>
#include <vector>
//--------------------------------------------------- Interfaces utilisées
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Shape>
//
//
//------------------------------------------------------------------------

class Shape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Move (vector<long> dXY) = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual bool InsideOf ( Point point1, Point point2) = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual string Command() = 0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual string GetName();
    // Mode d'emploi :
    //
    // Contrat :
    //

    vector<string> & GetSelections();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void addSelection(string selection);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Shape ( const Shape & unShape );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Shape ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Shape ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
protected:
//----------------------------------------------------- Attributs protégés
	string name;
	vector<string> inSelection;
private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Shape>

#endif // SHAPE_H
