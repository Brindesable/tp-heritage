/*************************************************************************
                           Polyline  -  description
                             -------------------
    d�but                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Interface de la classe <Polyline> (fichier Polyline) ------
#if ! defined ( POLYLINE_H )
#define POLYLINE_H

#include <vector>
#include "Shape.h"
//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Polyline>
//
//
//------------------------------------------------------------------------

class Polyline : public Shape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    void Move ( vector<long> dXY );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool InsideOf ( Point point1, Point point2);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual string Command ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Polyline ( const Polyline & unPolyline );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Polyline ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Polyline (string nom, vector<long> & data);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Polyline ( );
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
	vector<Point> points;
private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Polyline>

#endif // POLYLINE_H
