/*************************************************************************
                           Point  -  description
                             -------------------
    d�but                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point) ------
#if ! defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Point>
//
//
//------------------------------------------------------------------------

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s
	long x;
	long y;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Point>

#endif // POINT_H
