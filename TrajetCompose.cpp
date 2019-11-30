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

  cout <<". Trajet composé de " << etapes->GetNbTrajets() << " étapes :" << endl;

  for(int i=0;i<etapes->GetNbTrajets();i++)
  {
      cout << "     " << "Etape " << i+1 << " : ";
      etapes->GetListe()[i]->Affichage();
  }

  cout << endl;
  //Affichage des etapes
} //----- Fin de Affichage



//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const TrajetCompose & unTrajetCompose ) : Trajet(unTrajetCompose.villeDepart,unTrajetCompose.villeArrivee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet Compose>" << endl;
#endif

    *etapes=ListeTrajets(*unTrajetCompose.etapes);

} //----- Fin de Trajet Compose (constructeur de copie)

TrajetCompose::TrajetCompose (const char* vDepart, const char* vArrivee, ListeTrajets * liste) : Trajet(vDepart , vArrivee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

  etapes=liste;
  nbTrajets=etapes->GetNbTrajets();

} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

    for(int i=0;i<etapes->GetNbTrajets();i++)
        delete etapes->GetListe()[i];

    delete etapes;

} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
