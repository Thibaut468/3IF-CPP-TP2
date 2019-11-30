/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <ListeTrajets> (fichier ListeTrajets.h) ----------------
#if ! defined ( LISTETRAJETS_H )
#define LISTETRAJETS_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

const int NBAUGMENTATION = 10;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeTrajets>
//
//
//------------------------------------------------------------------------

class ListeTrajets
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Trajet ** GetListe() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    int GetNbTrajets() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AddTrajet(Trajet* nouveauTrajet);
    // Mode d'emploi :
    //
    // Contrat :
    //

    int RetirerDernier();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

    ListeTrajets ( const ListeTrajets & unListeTrajets);
    // Mode d'emploi :
    //
    // Contrat :
    //

    ListeTrajets (const int taille = NBAUGMENTATION);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ListeTrajets ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

   void augmenterTaille();
   // Mode d'emploi :
   //
   // Contrat :
   //

//----------------------------------------------------- Attributs protégés

   Trajet ** liste;
   int nbTrajets;
   int tailleMax;

};

//-------------------------------- Autres définitions dépendantes de <ListeTrajets>

#endif // LISTETRAJETS_H
