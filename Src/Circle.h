/*************************************************************************
                           Circle  -  description
                             -------------------
    d�but                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- longerface de la classe <Circle> (fichier Circle) ------
#if ! defined ( CIRCLE_H )
#define CIRCLE_H

#include <vector>
#include "Shape.h"
//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Circle>
//
//
//------------------------------------------------------------------------

class Circle : public Shape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s
	long radius;
	Point center;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Circle>

#endif // CIRCLE_H
