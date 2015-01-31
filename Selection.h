/*************************************************************************
                           Selection  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Interface de la classe <Selection> (fichier Selection) ------
#if ! defined ( SELECTION_H )
#define SELECTION_H

#include <set>
#include "Shape.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Selection>
//
//
//------------------------------------------------------------------------

class Selection
{
//----------------------------------------------------------------- PUBLIC

public:
//------------------------------------------------------- Attributs publiques

//----------------------------------------------------- Méthodes publiques
    void AddShape ( Shape * forme );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void RemoveShape (Shape * forme);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Move( vector<long> dXY, vector<string> & lineCommand);
    // Mode d'emploi :
    //
    // Contrat :
    //

    set<Shape*> & GetShapesInside();
    // Mode d'emploi :
    //
    // Contrat :
    //

    int GetNbShapesInside();
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Selection ( const Selection & unSelection );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Selection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Selection ( );
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
    set <Shape*> shapes;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Selection>

#endif // SELECTION_H
