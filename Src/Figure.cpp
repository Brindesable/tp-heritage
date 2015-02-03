/*************************************************************************
                          Figure  -  description
                             -------------------
    début                : 13-01-2015
    copyright            : (C) 2015 par B3329
*************************************************************************/

//---------- Réalisation de la classe <Figure> (fichier Figure) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <fstream>
#include <sstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Line.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
Code Figure::AddCircle ( string name, vector<long> & data, bool enableHistory)
// Algorithme :
//
{	vector<string> lineCommand;
	stringstream strstream;
	string line;

	if(!shapeExists(name))
	{   if(!selectionExists(name))
        {   //insere la forme dans l'arbre de données
            Circle * circle = new Circle(name,data);
            shapes.insert(make_pair(name,circle));
            //si la commande ne provient pas d'un fichier
            if(enableHistory)
            {   //enregistrement de la commande dans l'historique
                history("INSERT", circle->Command());
            }
        }
        else
        {   return NAME_ALREADY_USED;
        }
	}
	else
    {   return NAME_ALREADY_USED;
	}

	return OK;
} //----- Fin de Méthode

Code Figure::AddRectangle ( string name, vector<long> & data, bool enableHistory)
// Algorithme :
//
{	vector<string> lineCommand;
	string line;

	if(!shapeExists(name))
	{   if(!selectionExists(name))
        {   //insertion dans l'arbre des formes
            Rectangle * rec = new Rectangle(name, data);
            shapes.insert(make_pair(name,rec));
            //si la commande ne provient pas d'un fichier
            if(enableHistory)
            {   //enregistrement de la commande dans l'historique
                history("INSERT", rec->Command());
            }
        }
        else
        {   return NAME_ALREADY_USED;
        }
	}
	else
	{   return NAME_ALREADY_USED;
	}

	return OK;
} //----- Fin de Méthode

Code Figure::AddLine ( string name, vector<long> & data, bool enableHistory)
// Algorithme :
//
{   vector<string> lineCommand;
	stringstream strstream;
	string line;

	if(!shapeExists(name))
	{   if(!selectionExists(name))
        {
            Line * ligne = new Line(name, data);
            shapes.insert(pair<string,Shape*>(name,ligne));

            if(enableHistory)
            {   history("INSERT", ligne->Command());
            }
        }
        else
        {   return NAME_ALREADY_USED;
        }
	}
	else
    {   return NAME_ALREADY_USED;
	}

	return OK;
} //----- Fin de Méthode

Code Figure::AddPolyline ( string name, vector<long> & data, bool enableHistory)
// Algorithme :
//
{   vector<string> lineCommand;
	stringstream strstream;
	string line;

	if(!shapeExists(name))
	{   if(!selectionExists(name))
        {
            Polyline * polyligne = new Polyline(name, data);
            shapes.insert(pair<string,Shape*>(name,polyligne));

            if(enableHistory)
            {   history("INSERT", polyligne->Command());
            }
        }
        else
        {   return NAME_ALREADY_USED;
        }
	}
	else
	{   return NAME_ALREADY_USED;
	}

	return OK;
} //----- Fin de Méthode

Code Figure::AddSelection ( string name, vector<long> & data, int & nbObjSelected)
// Algorithme :
//
{
    //creation points a partir des arguments commande
	Point point1(data.at(0), data.at(1));
	Point point2(data.at(2), data.at(3));

    //itinitalisation compteur
	nbObjSelected = 0;

	if(!selectionExists(name))
	{   if(!shapeExists(name))
        {   Selection selec;
            //pour chaque forme
            map<string, Shape*>::iterator it;
            for(it=shapes.begin(); it!=shapes.end(); ++it)
            {   if(it->second->InsideOf(point1, point2))
                {   //si la forme est dans la selection
                    selec.AddShape(it->second);
                    //on signale à la forme qu'elle est dans une nouvelle selection
                    it->second->AddSelection(name);
                    //comptage des objets dans la selection
                    nbObjSelected++;
                }
            }
            //on ne cree la selection seulement si elle contient au moins un objet
            if(nbObjSelected > 0)
            {   selections.insert(pair<string,Selection>(name,selec));
            }
        }
        else
        {   return NAME_ALREADY_USED;
        }
	}
	else
    {   return NAME_ALREADY_USED;
	}

	return OK;
} //----- Fin de Méthode

Code Figure::Move (string name, vector<long> dXY, bool enableHistory, int & nbObjectsMoved)
// Algorithme :
//
{
	map<string,Shape*>::iterator it;
	map<string,Selection>::iterator ii;

    //on regarde d'abord dans les formes
	it=shapes.find(name);

	vector<string> lineCommand;
	stringstream strstream;
	string line;

	if(it!=shapes.end())
	{   //si c'est une forme
	    it->second->Move(dXY);
	    nbObjectsMoved = 1;
		//generation de l'historique
		strstream<<"MOVE "<<name<<" "<<dXY.at(0)<<" "<<dXY.at(1)<<endl;
		line = strstream.str();
		if(enableHistory)
		{   history("MOVE", line);
		}
	}
	else
    {   ii=selections.find(name);
        if(ii!=selections.end())
        {   //si c'est une selection
            vector<string> lineCommand;
            //on bouge les elements de la selection + generation de l'historique
            ii->second.Move(dXY, lineCommand);
            nbObjectsMoved = ii->second.GetNbShapesInside();

            commands.push_back(lineCommand);
			//suppression des redo eventuels
			redo.clear();
        }
        else
        {   return INEXISTING_OBJECT;
        }
	}

    return OK;
} //----- Fin de Méthode

string Figure::List ()
// Algorithme :
//
{   map<string,Shape*>::iterator it;
    stringstream ss;

    //pour chaque forme, on recupere sa commande associee
	if(shapes.size() > 0)
	{	for(it=shapes.begin(); it!=shapes.end(); ++it)
		{   ss << it->second->Command() << "\r\n";
		}
	}
	//s'il n'y a aucune forme
	else
	{	ss << "#anything created yet\r\n";
	}

	return ss.str();
} //----- Fin de Méthode

void Figure::Save (string nomFichier)
// Algorithme :
//
{   //on ouvre le fichier en écriture
	ofstream fichier(nomFichier.c_str(), ios::out);

    //s'il est accessible
	if(fichier)
	{
		map<string,Shape*>::iterator it;

		for(it=shapes.begin(); it!=shapes.end(); ++it)
		{
			fichier<<((*it).second)->Command()<<endl;;
		}
	}
	fichier.close();
} //----- Fin de Méthode

Code Figure::Delete (vector<string> & name, bool enableHistory, int & nbObjectsDeleted)
// Algorithme :
//
{
    vector<string> lineCommand;
    lineCommand.push_back("DELETE");
    map<string, Shape*>::iterator it;
    map<string, Selection>::iterator ii;

    //on met toutes les formes a supp dans un set pour eviter de supprimer deux fois un meme objet (qui appartient a deux selections
    // differentes par exemple)
    set<Shape*> shapesToDel;
    set<Shape*>::iterator is;

    //pour chaque nom dans la commande de suppression
    for(unsigned int i = 0; i < name.size(); i++)
    {
        it=shapes.find(name.at(i));
        if(it!=shapes.end())
        {   //on recupere l'objet
            shapesToDel.insert(it->second);
        }
        else
        {   ii=selections.find(name.at(i));
            if(ii!=selections.end())
            {   //on recupere les objets dans la selection
                set<Shape*> shapesInSelection = ii->second.GetShapesInside();
                for(is = shapesInSelection.begin(); is != shapesInSelection.end(); is++)
                {   shapesToDel.insert(*is);
                }
                //puis on supprime la selection
                selections.erase(ii);
            }
            else
            {   return INEXISTING_OBJECT;
            }
        }
    }

    nbObjectsDeleted = shapesToDel.size();
    for(is = shapesToDel.begin(); is != shapesToDel.end(); is++)
    {   //pour toutes les formes a supprimer
        lineCommand.push_back((*is)->Command());
        //recuperation des conteneurs (selections) des formes a supprimer
        // ceux-ci devront etre informé que la forme n'existe plus
        vector<string> selectionContainingShape = (*is)->GetSelections();
        for(unsigned int i = 0; i < selectionContainingShape.size(); i++)
        {   //recuperation de la selection concernee
            ii = selections.find(selectionContainingShape.at(i));
            if(ii != selections.end())
            {   //on lui indique que la forme qu'elle contient n'est plus disponible
                ii->second.RemoveShape(*is);
            }
        }
        //on supprime la forme dans l'arbre...
        shapes.erase((*is)->GetName());
        //... puis en memoire
        delete (*is);
    }
    if(enableHistory)
    {	commands.push_back(lineCommand);
		//suppression des redo eventuels
		redo.clear();
	}

    return OK;
} //----- Fin de Méthode

void Figure::Clear (bool enableHistory)
// Algorithme :
//
{
    map<string,Shape*>::iterator it;
    vector<string> lineCommand;
	lineCommand.push_back("DELETE");

    for(it = shapes.begin(); it != shapes.end(); ++it)
    {
        lineCommand.push_back(it->second->Command());
        delete it->second;
    }
	shapes.clear();
	selections.clear();

	if(enableHistory)
	{	commands.push_back(lineCommand);
		//suppression des redo eventuels
		redo.clear();
	}
} //----- Fin de Méthode

vector<string> Figure::Undo ()
// Algorithme :
//
{
	if(commands.size()!=0){
		redo.push_back(commands.back());
		commands.pop_back();
		return redo.back();
	}else{
		vector<string> vecteur;
		return vecteur;
	}

} //----- Fin de Méthode

vector<string> Figure::Redo ()
// Algorithme :
//
{
	if(redo.size()!=0){
		commands.push_back(redo.back());
		redo.pop_back();
		return commands.back();
	}else{
		vector<string> vecteur;
		return vecteur;
	}
} //----- Fin de Méthode

void Figure::AddToHistory (vector<string> history)
// Algorithme :
//
{	commands.push_back(history);
	//suppression des redo eventuels
	redo.clear();
} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Figure::Figure ( const Figure & unFigure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Figure>" << endl;
#endif
} //----- Fin deFigure (constructeur de copie)


Figure::Figure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Figure>" << endl;
#endif
} //----- Fin deFigure


Figure::~Figure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Figure>" << endl;
#endif
    //l'arbre contient des pointeurs vers des formes
    map<string,Shape*>::iterator it;
    for(it = shapes.begin(); it != shapes.end(); ++it)
    {   delete it->second;
    }
} //----- Fin de ~Figure

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

bool Figure::shapeExists(string name)
{   //iterateurs sur arbres
    map<string,Shape*>::iterator it;
    //recherche du nom
	it=shapes.find(name);

	if(it==shapes.end())
	{   return false;
	}
	return true;
}

bool Figure::selectionExists(string name)
{   //iterateur sur l'arbre
    map<string,Selection>::iterator ii;
    //recherche du nom
    ii=selections.find(name);

    if(ii==selections.end())
	{   return false;
	}
	return true;
}

void  Figure::history(string action, string objects)
{
    vector<string> lineHistory;
    lineHistory.push_back(action);
	lineHistory.push_back(objects);

    commands.push_back(lineHistory);
	//suppression des redo eventuels
	redo.clear();
}
