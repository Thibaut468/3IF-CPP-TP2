/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void TrajetSimple::Affichage () const
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel à l'affichage de <TrajetSimple>" << endl;
#endif

  Trajet::Affichage();
  cout <<" Trajet Simple. Moyen de transport : " << moyenTransport << endl;

  //Affichage des etapes
} //----- Fin de Affichage


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple (const char* vDepart, const char* vArrivee, const char* mTransport) : Trajet(vDepart, vArrivee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

  moyenTransport = new char [strlen(mTransport) + 1];
  strcpy( moyenTransport, mTransport);

} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
delete [] moyenTransport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
