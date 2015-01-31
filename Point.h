/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point) ------
#if ! defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Point>
//
//
//------------------------------------------------------------------------

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Move ( long dX, long dY );
    // Mode d'emploi :
    //
    // Contrat :
    //

    long GetX ();
    // Mode d'emploi :
    //
    // Contrat :
    //

	long GetY ();
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point & unPoint );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

	Point ();
    // Mode d'emploi :
    //
    // Contrat :
    //


    Point (long posX, long posY);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Point ( );
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
	long x;
	long y;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Point>

#endif // POINT_H
