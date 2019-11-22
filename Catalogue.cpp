/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

ListeTrajets Catalogue::GetListeTraj()
// Algorithme :
//
{
   return listeTraj;
} //----- Fin de GetListeTraj

void Catalogue::RechercheSimple(const char * vDepart, const char* vArrivee)
// Algorithme :
//
{

} //----- Fin de GetListeTraj

void Catalogue::RechercheComplexe(const char * vDepart, const char* vArrivee)
// Algorithme :
//
{

} //----- Fin de GetListeTraj

void Catalogue::Presenter()
// Algorithme :
//
{
   int nbTrajets = listeTraj.GetNbTrajets();
   cout << nbTrajets << endl;
   if(nbTrajets==0)
   {
      cout << "---------- CATALOGUE VIDE ----------" << endl;
   }
   else
   {
      Trajet ** traj = listeTraj.GetListe();
      cout << "---------- CONTENU DU CATALOGUE ----------" << endl;
      for(int i=0; i<nbTrajets;i++)
      {
         traj[i]->Affichage();
      }
   }
} //----- Fin de Presenter

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue () : listeTraj()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
