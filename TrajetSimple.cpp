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
  cout <<" en " << moyenTransport << endl;

  //Affichage des etapes
} //----- Fin de Affichage


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const TrajetSimple &unTrajetSimple) : Trajet(unTrajetSimple.villeDepart,unTrajetSimple.villeArrivee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet Simple>" << endl;
#endif

    moyenTransport = new char [strlen(unTrajetSimple.moyenTransport) + 1];
    strcpy( moyenTransport, unTrajetSimple.moyenTransport);


} //----- Fin de Trajet Simple (constructeur de copie)

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
