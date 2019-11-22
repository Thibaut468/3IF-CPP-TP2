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

void ListeTrajets::AddTrajetSimple()
// Algorithme :
//
{
   listeTraj.AddTrajet(CreateTrajetSimple());
} //----- Fin de addTrajetSimple

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

char * AskVilleArrivee() const
// Algorithme :
//
{
   char * ret[TAILLE_ENTREE_VILLE];
   cout << "Saisir la ville de départ : " << endl;
   cin >> ret;
   return ret;
} //----- Fin de AskVilleDepart

char * AskVilleDepart() const
// Algorithme :
//
{
   char * ret[TAILLE_ENTREE_VILLE];
   cout << "Saisir la ville d'arrivée : " << endl;
   cin >> ret;
   return ret;
} //----- Fin de AskVilleArrivee

char * AskMoyenTransport() const
// Algorithme :
//
{
   char * ret[TAILLE_ENTREE_MOYEN_TRANSPORT];
   cout << "Saisir le moyen de transport : " << endl;
   cin >> ret;
   return ret;
} //----- Fin de AskMoyenTransport

TrajetSimple * Catalogue::CreateTrajetSimple() const
// Algorithme :
//
{
   char * vDepart = AskVilleDepart();
   char * vArrivee = AskVilleArrivee();
   char * vMoyenTransport = AskMoyenTransport();
   TrajetSimple * nouveauTrajet = new TrajetSimple(vDepart,vArrivee,vMoyenTransport);
   return nouveauTrajet;
} //----- Fin de CreateTrajetSimple

//----------------------------------------------------- Méthodes protégées
