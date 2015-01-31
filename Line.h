/*************************************************************************
                           Line  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Interface de la classe <Line> (fichier Line) ------
#if ! defined ( LINE_H )
#define LINE_H

#include <vector>
#include "Polyline.h"
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Line>
//
//
//------------------------------------------------------------------------

class Line : public Polyline
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string Command ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Line ( const Line & unLine );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Line ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Line (string nom, vector<long> & data);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Line ( );
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

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Line>

#endif // LINE_H
