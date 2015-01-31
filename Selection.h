/*************************************************************************
                           Selection  -  description
                             -------------------
    d�but                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Interface de la classe <Selection> (fichier Selection) ------
#if ! defined ( SELECTION_H )
#define SELECTION_H

#include <set>
#include "Shape.h"
//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Selection>
//
//
//------------------------------------------------------------------------

class Selection
{
//----------------------------------------------------------------- PUBLIC

public:
//------------------------------------------------------- Attributs publiques

//----------------------------------------------------- M�thodes publiques
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s
    set <Shape*> shapes;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Selection>

#endif // SELECTION_H
