/*************************************************************************
                           Circle  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- longerface de la classe <Circle> (fichier Circle) ------
#if ! defined ( CIRCLE_H )
#define CIRCLE_H

#include <vector>
#include "Shape.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Circle>
//
//
//------------------------------------------------------------------------

class Circle : public Shape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Move ( vector<long> dXY);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool InsideOf ( Point point1, Point point2);
    // Mode d'emploi :
    //
    // Contrat :
    //

    string Command ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Circle ( const Circle & unCircle );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Circle ();
    // Mode d'emploi :
    //
    // Contrat :
    //


    Circle (string name, vector<long> & data);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Circle ( );
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

private:
//------------------------------------------------------- Attributs privés
	long radius;
	Point center;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Circle>

#endif // CIRCLE_H
