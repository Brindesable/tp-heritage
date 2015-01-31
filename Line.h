/*************************************************************************
                           Line  -  description
                             -------------------
    d�but                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Interface de la classe <Line> (fichier Line) ------
#if ! defined ( LINE_H )
#define LINE_H

#include <vector>
#include "Polyline.h"
//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Line>
//
//
//------------------------------------------------------------------------

class Line : public Polyline
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s
private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Line>

#endif // LINE_H
