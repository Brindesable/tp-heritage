/*************************************************************************
                           Application  -  description
                             -------------------
    d�but                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Interface de la classe <Application> (fichier Application) ------
#if ! defined ( Application_H )
#define Application_H

#include <vector>
#include <string>
using namespace std;
//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
class Figure;
//------------------------------------------------------------------------
// R�le de la classe <Application>
//
//
//------------------------------------------------------------------------

class Application
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    void Launch();
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Application ( const Application & unApplication );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Application ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Application ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es
    bool interpret(string cmdLine, bool enableHistory, bool verbose);

    //infraction au guide de style, struct necessaire pour la fonction
    struct CmdArgs;
    bool parseLine(CmdArgs & cmdArgs, stringstream & line, int nbArgs);

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s
    Figure &  figure;

    int infinitePoints;
    int infiniteObjectNames;
    int noArgs;
    bool urMove;
    bool urDelete;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s
    struct CmdType
    {   string toString;
        int nbArgs;
    };

    struct CmdArgs
    {   vector<string> objects;
        vector<long> numbers;
    };

    CmdType cmdCircle;
    CmdType cmdRectangle;
    CmdType cmdLine;
    CmdType cmdPolyline;
    CmdType cmdSelection;
    CmdType cmdDelete;
    CmdType cmdMove;
    CmdType cmdEnum;
    CmdType cmdUndo;
    CmdType cmdRedo;
    CmdType cmdLoad;
    CmdType cmdSave;
    CmdType cmdClear;
    CmdType cmdExit;
};

//----------------------------------------- Types d�pendants de <Application>

#endif // Application_H
