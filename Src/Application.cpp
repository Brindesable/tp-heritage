/*************************************************************************
                           Application  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Réalisation de la classe <Application> (fichier Application) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "Application.h"
#include "Figure.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Application::Launch()
{
    //main loop
    for (std::string line; std::getline(std::cin, line) && interpret(line, true, true) != EXIT;) {
    }
}

//-------------------------------------------- Constructeurs - destructeur
Application::Application ( const Application & unApplication ) : figure(*(new Figure()))
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Application>" << endl;
#endif
} //----- Fin de Application (constructeur de copie)


Application::Application ( ) : figure(*(new Figure()))
// Algorithme :
//
{
    infinitePoints = -1;
    infiniteObjectNames = -2;
    noArgs = 0;
    urMove = false;
    urDelete = false;

    cmdCircle.toString = "C";
    cmdCircle.nbArgs = 4;

    cmdRectangle.toString = "R";
    cmdRectangle.nbArgs = 5;

    cmdLine.toString = "L";
    cmdLine.nbArgs = 5;

    cmdPolyline.toString = "PL";
    cmdPolyline.nbArgs = infinitePoints;

    cmdSelection.toString = "S";
    cmdSelection.nbArgs = 5;

    cmdDelete.toString = "DELETE";
    cmdDelete.nbArgs = infiniteObjectNames;

    cmdMove.toString = "MOVE";
    cmdMove.nbArgs = 3;

    cmdEnum.toString = "LIST";
    cmdEnum.nbArgs = noArgs;

    cmdUndo.toString = "UNDO";
    cmdUndo.nbArgs = noArgs;

    cmdRedo.toString = "REDO";
    cmdRedo.nbArgs = noArgs;

    cmdLoad.toString = "LOAD";
    cmdLoad.nbArgs = 1;

    cmdSave.toString = "SAVE";
    cmdSave.nbArgs = 1;

    cmdClear.toString = "CLEAR";
    cmdClear.nbArgs = noArgs;

    cmdExit.toString = "EXIT";
    cmdClear.nbArgs = noArgs;
#ifdef MAP
    cout << "Appel au constructeur de <Application>" << endl;
#endif
} //----- Fin de Application


Application::~Application ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Application>" << endl;
#endif
} //----- Fin de ~Application


//------------------------------------------------------------------ PRIVE
//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
Code Application::interpret(string cmdString, bool enableHistory, bool verbose)
{
    stringstream cmdStringStream(cmdString);
    string cmdGiven;
    CmdArgs cmd;
    Code code;

    cmdStringStream >> cmdGiven;

    if(cmdGiven[0] == '#')
    {   code = COMMENT;
    }
    //================================================================================= Command C
    if(cmdGiven == cmdCircle.toString)
    {   //la ligne est bien formee
        if(parseLine(cmd, cmdStringStream, cmdCircle.nbArgs))
        {   //ce n'est pas une commande "reverse"
            if(!urDelete){
				//ajout du cercle
				code = figure.AddCircle(cmd.objects.at(0), cmd.numbers, enableHistory);

				if(verbose && code == OK)
                {   cout << "OK\r\n#1 object(s) created\r\n";
                }
            }
            else
            {   //suppression du cercle
                interpret("DELETE " + cmd.objects.at(0), enableHistory, verbose);
			}
        }
        else
        {   code = ERROR_SYNTAX;
        }
    }
    //================================================================================= Command R
    else if(cmdGiven == cmdRectangle.toString)
    {   //la ligne est bien formee
        if(parseLine(cmd, cmdStringStream, cmdRectangle.nbArgs))
        {   //ce n'est pas un commande "reverse" (undo/redo)
			if(!urDelete){
				//insertion du rectangle
				code = figure.AddRectangle(cmd.objects.at(0), cmd.numbers, enableHistory);
				if(verbose && code == OK)
                {   cout << "OK\r\n#1 object(s) created\r\n";
                }
            }
            else
            {   //suppression du rectangle
                interpret("DELETE " + cmd.objects.at(0),enableHistory, verbose);
			}
        }
        else
        {   code = ERROR_SYNTAX;
        }
    }
    //================================================================================= Command L
    else if(cmdGiven == cmdLine.toString)
    {   //commande bien formee
        if(parseLine(cmd, cmdStringStream, cmdLine.nbArgs))
        {   //ce n'est pas une commande "reverse"
            if(!urDelete)
            {   //insertion de la ligne
                code = figure.AddLine(cmd.objects.at(0), cmd.numbers, enableHistory);
				if(verbose && code == OK)
                {   cout << "OK\r\n#1 object(s) created\r\n";
                }
            }
            else
			{   //suppression de la ligne
			    interpret("DELETE "+cmd.objects.at(0),enableHistory, verbose);
			}
        }
        else
        {   code = ERROR_SYNTAX;
        }
    }
    //================================================================================= Command PL
    else if(cmdGiven == cmdPolyline.toString)
    {   //commande bien formee
        if(parseLine(cmd, cmdStringStream, cmdPolyline.nbArgs))
        {   //ce n'est pas une commande reverse
            if(!urDelete)
			{   //insertion de la polyligne
				code = figure.AddPolyline(cmd.objects.at(0), cmd.numbers, enableHistory);
				if(verbose && code == OK)
                {   cout << "OK\r\n#1 object(s) created\r\n";
                }
            }
            else
            {   //suppression de la polyligne
                interpret("DELETE " + cmd.objects.at(0), enableHistory, verbose);
			}
        }
        else
        {   code = ERROR_SYNTAX;
        }
    }
    //================================================================================= Command S
    else if(cmdGiven == cmdSelection.toString)
    {   //commande bien formee
        if(parseLine(cmd, cmdStringStream, cmdSelection.nbArgs))
        {   //nombre d'objets selectionnes
            int nbObjects = 0;
            code = figure.AddSelection(cmd.objects.at(0), cmd.numbers, nbObjects);
            if(code == OK)
            {   if(nbObjects > 0)
                {   cout << "OK\r\n#" << nbObjects << " object(s) selected\r\n";
                }
                else
                {   cout << "ERR\r\n#0 object(s) selected\r\n";
                }
            }
        }
        else
        {   code = ERROR_SYNTAX;
        }
    }
    //================================================================================= Command DELETE
    else if(cmdGiven == cmdDelete.toString)
    {   //commande bien formee
        if(parseLine(cmd, cmdStringStream, cmdDelete.nbArgs))
        {   //nombre d'objets qui vont etre supprimes
            int nbObjects = 0;
            code = figure.Delete(cmd.objects, enableHistory, nbObjects);

            if(verbose && code == OK)
            {   if(nbObjects > 0)
                {   cout << "OK\r\n#" << nbObjects << " object(s) deleted\r\n";
                }
                else
                {   cout << "ERR\r\n#0 object(s) deleted\r\n";
                }
            }
        }
        else
        {   code = ERROR_SYNTAX;
        }
    }
    //================================================================================= Command MOVE
    else if(cmdGiven == cmdMove.toString)
    {   //commande bien formee
        if(parseLine(cmd, cmdStringStream, cmdMove.nbArgs))
        {   //nb d'objets qui vont bouger
            int nbObjects = 0;

			//si la commande est "reverse", on inverse les direction
			if(urMove)
			{   vector<long>::iterator it;
				for(it=cmd.numbers.begin(); it!=cmd.numbers.end(); ++it)
				{   (*it)=0-(*it);
				}
			}

			code = figure.Move(cmd.objects.at(0), cmd.numbers, enableHistory, nbObjects);
            if(verbose && code == OK)
            {   if(nbObjects > 0)
                {   cout << "OK\r\n#" << nbObjects << " object(s) moved\r\n";
                }
                else
                {   cout << "ERR\r\n#0 object(s) moved\r\n";
                }
            }
        }
        else
        {   code = ERROR_SYNTAX;
        }
    }
    //================================================================================= Command LIST
    else if(cmdGiven == cmdEnum.toString)
    {   //liste de tous les objets
        cout << figure.List();
    }
    //================================================================================= Command UNDO
    else if(cmdGiven == cmdUndo.toString)
    {
        //on va chercher l'historique de la dernière commande
		vector<string>undo=figure.Undo();
		vector<string> :: iterator it;

        //si elle existe
		if(undo.size() > 0)
		{   //si on doit undo un MOVE, on appelle l'interpreteur en specifiant le reverse
			if(undo.front()=="MOVE")
		    {   urMove=true;
				for(it=undo.begin()+1; it!=undo.end(); ++it)
				{
					interpret(*it, false, false);
				}
				urMove=false;
		        cout << "OK\r\n#" << undo.size() - 1 << " object(s) moved\r\n";
			}
			//si on doit undo un DELETE, on recree les objets supprimes
			if(undo.front()=="DELETE"){
				for(it=undo.begin()+1; it!=undo.end(); ++it)
				{
					interpret(*it, false, false);
				}
				cout << "OK\r\n#" << undo.size() - 1 << " object(s) created\r\n";
			}
			//si on doit undo un INSERT, on supprime les objets ajoute
			if(undo.front()=="INSERT"){
				urDelete=true;
				for(it=undo.begin()+1; it!=undo.end(); ++it)
				{
					interpret(*it, false, false);
				}
				urDelete=false;
				cout << "OK\r\n#" << undo.size() - 1 << " object(s) deleted\r\n";
			}
		}
		else
		{	cout << "ERR\r\n#no command to undo\r\n";
		}
    }
    //================================================================================= Command REDO
    else if(cmdGiven == cmdRedo.toString)
    {   //on recupere les commandes qui viennent d'etre UNDO
        vector<string>redo=figure.Redo();
        vector<string> :: iterator it;

		if(redo.size() > 0)
		{   // si c'est un INSERT, on recree les objets
		    if(redo.front()=="INSERT"){
				for(it=redo.begin()+1; it!=redo.end(); ++it)
				{
					interpret(*it, false, false);
				}
				cout << "OK\r\n#" << redo.size() - 1 << " object(s) created\r\n";
			}
			// si c'est un move, on bouge normalement les formes
			if(redo.front()=="MOVE"){
				for(it=redo.begin()+1; it!=redo.end(); ++it)
				{
					interpret(*it, false, false);
				}
				cout << "OK\r\n#" << redo.size() - 1 << " object(s) moved\r\n";
			}
			// si c'est un delete, on resupprime les formes
			if(redo.front()=="DELETE"){
				urDelete=true;
				for(it=redo.begin()+1; it!=redo.end(); ++it)
				{
					interpret(*it, false, false);
				}
				urDelete=false;
				cout << "OK\r\n#" << redo.size() - 1 << " object(s) deleted\r\n";
			}
		}
		else
		{	cout << "ERR\r\n#no undo before\r\n";
		}
    }
    //================================================================================= Command LOAD
    else if(cmdGiven == cmdLoad.toString)
    {   //la commande est bien formee
        if(parseLine(cmd, cmdStringStream, cmdLoad.nbArgs))
        {   // on ouvre en lecture
			ifstream fichier (cmd.objects.at(0).c_str(), ios::in);
			// si l'ouverture a fonctionné
			if(fichier)
			{
			    //historique des commandes d'insertion qui vont être réalisées
				vector<string>history;
				history.push_back("INSERT");
				// déclaration d'une chaîne qui contiEndRa la ligne lue
				string contenu;
				//code de l'insertion
				Code codeLoad = OK;
				//pour chaque ligne du fichier
				while(getline(fichier, contenu) && (codeLoad == OK || codeLoad == COMMENT))
				{   //on interprete la ligne du fichier
					codeLoad = interpret(contenu, false, false);
					//si l'insertion a fonctionne
					if(codeLoad == OK)
                    {   history.push_back(contenu);
                    }
				}
				//si toutes les insertions du fichier on fonctionnés sans erreur
				if(codeLoad == OK)
                {   figure.AddToHistory(history);
                    code = OK;
                    cout << "OK\r\n#" << history.size() - 1 << " object(s) created\r\n";
                }
                //sinon on n'enregistre pas l'historique et on defait tout les commandes
                else if(code != COMMENT)
                {   urDelete=true;
                    for(int i = 1; i < history.size(); i++)
                    {   interpret(history[i], false, false);
                    }
                    urDelete=false;
                    code = ERROR_LOADING;
                }
				fichier.close(); //Quand on a tout finit on ferme le fichier
			}
			else
			{   cout << "ERR\r\n#unable to open file" << endl;
			}
		}
        else
        {   code = ERROR_SYNTAX;
        }
    }
    //================================================================================= Command SAVE
    else if(cmdGiven == cmdSave.toString)
    {   //la commande est bien formee
        if(parseLine(cmd, cmdStringStream, cmdSave.nbArgs))
        {   //la figure sauvegarde elle meme le fichier
            figure.Save(cmd.objects.at(0));
            cout << "OK\r\n";
        }
        else
        {   code = ERROR_SYNTAX;
        }
    }
    //================================================================================= Command CLEAR
    else if(cmdGiven == cmdClear.toString)
    {   figure.Clear(enableHistory);
		cout << "OK\r\n#everything cleared\r\n";
    }
    //================================================================================= Command EXIT
    else if(cmdGiven == cmdExit.toString)
    {   code = EXIT;
    }
    //=================================================================================
    else
    {   code = ERROR_SYNTAX;
    }

    if(verbose)
    {
        switch(code)
        {
            case OK :
                break;
            case COMMENT :
                break;
            case NAME_ALREADY_USED :
                cout << "ERR\r\n#name already used\r\n";
                break;
            case INEXISTING_OBJECT :
                cout << "ERR\r\n#unknown object\r\n";
                break;
            case ERROR_SYNTAX :
                cout << "ERR\r\n#error syntax\r\n";
                break;
            case ERROR_LOADING :
                cout << "ERR\r\n#loading error\r\n";
                break;
        }
    }

    return code;
}

bool Application::parseLine(CmdArgs & cmd, stringstream & line, int nbArgs)
{
    string stringBuf;
    int intBuf(0);
    bool firstLoop = true;

    while(line)
    {   if(firstLoop || nbArgs == infiniteObjectNames)
        {   line >> stringBuf;
            if(!line)
                break;
            cmd.objects.push_back(stringBuf);
        }
        else
        {   line >> intBuf;
            if(!line)
                break;
            cmd.numbers.push_back(intBuf);
        }
        firstLoop = false;
    }

    if((nbArgs == infinitePoints &&
       cmd.numbers.size() % 2 == 0) ||
       nbArgs == infiniteObjectNames ||
       nbArgs == static_cast<int>(cmd.numbers.size() + cmd.objects.size()))
    {   return true;
    }
    else
    {   return false;
    }
}
