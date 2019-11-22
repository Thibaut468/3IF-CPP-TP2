/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
 void Trajet::Affichage () const
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'affichage de <Trajet>" << endl;
#endif
  cout << "Trajet de: " << villeDepart << " à " << villeArrivee << endl;
} //----- Fin de Affichage

char* Trajet::GetVilleDepart () const
// Algorithme :
//
{
   return villeDepart;
} //----- Fin de GetVilleDepart

char* Trajet::GetVilleArrivee () const
// Algorithme :
//
{
   return villeArrivee;
} //----- Fin de GetVilleArrivee

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const char* vDepart, const char* vArrivee )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
  villeDepart = new char [strlen(vDepart) + 1];
  villeArrivee = new char [strlen(vArrivee) + 1];
  strcpy ( villeDepart, vDepart );
  strcpy ( villeArrivee, vArrivee );

} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif

delete [] villeDepart;
delete [] villeArrivee;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
