/*************************************************************************
                          Figure  -  description
                             -------------------
    d�but                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Interface de la classe <Figure> (fichier Figure) ------
#if ! defined ( FIGURE_H )
#define FIGURE_H

#include <map>
#include <vector>
#include "Shape.h"
#include "Selection.h"
#include "Application.h"
//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum Code
{
    OK = 1,
    NAME_ALREADY_USED,
    INEXISTING_OBJECT
};
//------------------------------------------------------------------------
// R�le de la classe <Figure>
//
//
//------------------------------------------------------------------------

class Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    Code AddSelection ( string name, vector<long> & data, int & nbObjects );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Code AddCircle ( string name, vector<long> & data, bool enableHistory);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Code AddRectangle ( string name, vector<long> & data, bool enableHistory );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Code AddLine ( string name, vector<long> & data, bool enableHistory );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Code AddPolyline ( string name, vector<long> & data, bool enableHistory );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Code Move (string name, vector<long> dXY, bool enableHistory, int & nbObjectsMoved);
    // Mode d'emploi :
    //
    // Contrat :
    //

    string List ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Save (string nomFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Code Delete (vector<string> & name, bool enableHistory, int & nbObjectsDeleted);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Clear (bool enableHistory);
    // Mode d'emploi :
    //
    // Contrat :
    //

    vector<string> Undo ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    vector<string> Redo ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AddToHistory(vector<string> histoire);
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
   Figure ( const Figure & unFigure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

   Figure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Figure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es
    bool shapeExists(string name);
    bool selectionExists(string name);
    void history(string action, string objects);

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s
	map<string, Shape *> shapes;
	map<string,Selection> selections;
	vector< vector<string> > commands;
	vector< vector<string> > redo;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <Figure>

#endif // FIGURE_H
