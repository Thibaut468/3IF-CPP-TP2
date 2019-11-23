/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Affichage () const
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel à l'affichage de <TrajetCompose>" << endl;
#endif

  Trajet::Affichage();

  cout <<" Trajet composé. Liste des Etapes: " << endl;

  etapes->AffichageTrajets();

  //Affichage des etapes
} //----- Fin de Affichage



//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const char* vDepart, const char* vArrivee, const ListeTrajets* liste ) : Trajet(vDepart , vArrivee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

  etapes=(ListeTrajets*) liste;
  nbTrajets=etapes->GetNbTrajets();

} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

delete [] etapes;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
