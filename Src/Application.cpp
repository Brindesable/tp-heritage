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
    for (std::string line; std::getline(std::cin, line);) {
       interpret(line, true, true);
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
void Application::interpret(string cmdString, bool enableHistory, bool verbose)
{
    stringstream cmdStringStream(cmdString);
    string cmdGiven;
    CmdArgs cmd;
    Code code;

    cmdStringStream >> cmdGiven;

    if(cmdGiven == cmdCircle.toString)
    {   if(parseLine(cmd, cmdStringStream, cmdCircle.nbArgs))
        {
			if(!urDelete){
				code = figure.AddCircle(cmd.objects.at(0), cmd.numbers, enableHistory);
				if(verbose)
                {
                    switch(code)
                    {
                        case OK:
                            cout << "OK\r\n#1 object(s) created\r\n";
                            break;
                        case NAME_ALREADY_USED :
                            break;
                        case INEXISTING_OBJECT :
                            break;
                    }
                }
            }
            else
            {   interpret("DELETE " + cmd.objects.at(0), enableHistory, verbose);
			}
        }
        else
        {   cout << "ERR\r\n#error syntax\r\n";
        }
    }
    else if(cmdGiven == cmdRectangle.toString)
    {   if(parseLine(cmd, cmdStringStream, cmdRectangle.nbArgs))
        {
			if(!urDelete){
				code = figure.AddRectangle(cmd.objects.at(0), cmd.numbers, enableHistory);
				if(verbose)
                {
                    switch(code)
                    {
                        case OK:
                            cout << "OK\r\n#1 object(s) created\r\n";
                            break;
                        case NAME_ALREADY_USED :
                            break;
                        case INEXISTING_OBJECT :
                            break;
                    }
                }
            }
            else
            {   interpret("DELETE " + cmd.objects.at(0),enableHistory, verbose);
			}
        }
        else
        {   cout << "ERR\r\n#error syntax\r\n";
        }
    }
    else if(cmdGiven == cmdLine.toString)
    {   if(parseLine(cmd, cmdStringStream, cmdLine.nbArgs))
        {
			if(!urDelete)
            {   code = figure.AddLine(cmd.objects.at(0), cmd.numbers, enableHistory);
				if(verbose)
                {
                    switch(code)
                    {
                        case OK:
                            cout << "OK\r\n#1 object(s) created\r\n";
                            break;
                        case NAME_ALREADY_USED :
                            break;
                        case INEXISTING_OBJECT :
                            break;
                    }
                }
            }
            else
			{   interpret("DELETE "+cmd.objects.at(0),enableHistory, verbose);
			}
        }
        else
        {   cout << "ERR\r\n#error syntax\r\n";
        }
    }
    else if(cmdGiven == cmdPolyline.toString)
    {   if(parseLine(cmd, cmdStringStream, cmdPolyline.nbArgs))
        {
            if(!urDelete){
				code = figure.AddPolyline(cmd.objects.at(0), cmd.numbers, enableHistory);
				if(verbose)
                {
                    switch(code)
                    {
                        case OK:
                            cout << "OK\r\n#1 object(s) created\r\n";
                            break;
                        case NAME_ALREADY_USED :
                            break;
                        case INEXISTING_OBJECT :
                            break;
                    }
                }
            }
            else
            {   interpret("DELETE " + cmd.objects.at(0), enableHistory, verbose);
			}
        }
        else
        {   cout << "ERR\r\n#error syntax\r\n";
        }
    }
    else if(cmdGiven == cmdSelection.toString)
    {   if(parseLine(cmd, cmdStringStream, cmdSelection.nbArgs))
        {   int nbObjects = 0;
            code = figure.AddSelection(cmd.objects.at(0), cmd.numbers, nbObjects);
            switch(code)
            {
                case OK:
                    if(nbObjects > 0)
                    {   cout << "OK\r\n#" << nbObjects << " object(s) selected\r\n";
                    }
                    else
                    {   cout << "ERR\r\n#0 object(s) selected\r\n";
                    }
                    break;
                case NAME_ALREADY_USED :
					break;
				case INEXISTING_OBJECT :
					break;
            }
        }
        else
        {   cout << "ERR\r\n#error syntax\r\n";
        }
    }
    else if(cmdGiven == cmdDelete.toString)
    {   if(parseLine(cmd, cmdStringStream, cmdDelete.nbArgs))
        {   int nbObjects = 0;
            code = figure.Delete(cmd.objects, enableHistory, nbObjects);
            if(verbose)
            {
                switch(code)
                {
                    case OK:
                        if(nbObjects > 0)
                        {   cout << "OK\r\n#" << nbObjects << " object(s) deleted\r\n";
                        }
                        else
                        {   cout << "ERR\r\n#0 object(s) deleted\r\n";
                        }
                        break;
                    case NAME_ALREADY_USED :
                        break;
                    case INEXISTING_OBJECT :
                        break;
                }
            }
        }
        else
        {   cout << "ERR\r\n#error syntax\r\n";
        }
    }
    else if(cmdGiven == cmdMove.toString)
    {   if(parseLine(cmd, cmdStringStream, cmdMove.nbArgs))
        {   int nbObjects = 0;
			if(urMove)
			{   vector<long>::iterator it;
				for(it=cmd.numbers.begin(); it!=cmd.numbers.end(); ++it)
				{
					(*it)=0-(*it);
				}
			}
			code = figure.Move(cmd.objects.at(0), cmd.numbers, enableHistory, nbObjects);
            if(verbose)
            {
                switch(code)
                {
                    case OK:
                        if(nbObjects > 0)
                        {   cout << "OK\r\n#" << nbObjects << " object(s) moved\r\n";
                        }
                        else
                        {   cout << "ERR\r\n#0 object(s) moved\r\n";
                        }
                        break;
                    case NAME_ALREADY_USED :
                        break;
                    case INEXISTING_OBJECT :
                        break;
                }
            }
        }
        else
        {   cout << "ERR\r\n#error syntax\r\n";
        }
    }
    else if(cmdGiven == cmdEnum.toString)
    {
        cout << figure.List();
    }
    else if(cmdGiven == cmdUndo.toString)
    {
		vector<string>undo=figure.Undo();
		vector<string> :: iterator it;

		if(undo.size() > 0)
		{
			if(undo.front()=="MOVE")
		    {   urMove=true;
				for(it=undo.begin()+1; it!=undo.end(); ++it)
				{
					interpret(*it, false, false);
				}
				urMove=false;
		        cout << "OK\r\n#" << undo.size() - 1 << " object(s) moved\r\n";
			}
			if(undo.front()=="DELETE"){
				for(it=undo.begin()+1; it!=undo.end(); ++it)
				{
					interpret(*it, false, false);
				}
				cout << "OK\r\n#" << undo.size() - 1 << " object(s) created\r\n";
			}
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
    else if(cmdGiven == cmdRedo.toString)
    {
        vector<string>redo=figure.Redo();
        vector<string> :: iterator it;

		if(redo.size() > 0)
		{
		    if(redo.front()=="INSERT"){
				for(it=redo.begin()+1; it!=redo.end(); ++it)
				{
					interpret(*it, false, false);
				}
				cout << "OK\r\n#" << redo.size() - 1 << " object(s) created\r\n";
			}
			if(redo.front()=="MOVE"){
				for(it=redo.begin()+1; it!=redo.end(); ++it)
				{
					interpret(*it, false, false);
				}
				cout << "OK\r\n#" << redo.size() - 1 << " object(s) moved\r\n";
			}
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
    else if(cmdGiven == cmdLoad.toString)
    {   if(parseLine(cmd, cmdStringStream, cmdLoad.nbArgs))
        {
			ifstream fichier (cmd.objects.at(0).c_str(), ios::in);// on ouvre en lecture
			if(fichier)  // si l'ouverture a fonctionné
			{
				vector<string>history;
				history.push_back("INSERT");
				string contenu;  // déclaration d'une chaîne qui contiEndRa la ligne lue
				while(getline(fichier, contenu))
				{  // on met la ligne dans "contenu"
					interpret(contenu, false, false);
					history.push_back(contenu);
				}
				figure.AddToHistory(history);
				fichier.close(); //Quand on a tout finit on ferme le fichier
			}else{
				cerr << "ERR\r\n#unable to open file" << endl;
			}
		}
        else
        {   cout << "ERR\r\n#error syntax\r\n";
        }
    }
    else if(cmdGiven == cmdSave.toString)
    {   if(parseLine(cmd, cmdStringStream, cmdSave.nbArgs))
        {
            figure.Save(cmd.objects.at(0));
            cout << "OK\r\n";
        }
        else
        {   cout << "ERR\r\n#error syntax\r\n";
        }
    }
    else if(cmdGiven == cmdClear.toString)
    {
        figure.Clear(enableHistory);
		cout << "OK\r\n#everything cleared\r\n";
    }
    else if(cmdGiven == cmdExit.toString)
    {
        cout << "exit\r\n";
    }
    else
    {   cout << "ERR\r\n#unknown command\r\n";
    }

    switch(code)
    {
		case OK :
			break;
        case NAME_ALREADY_USED :
            cout << "ERR\r\n#name already used\r\n";
            break;
        case INEXISTING_OBJECT :
            cout << "ERR\r\n#unknown object\r\n";
            break;
    }
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
