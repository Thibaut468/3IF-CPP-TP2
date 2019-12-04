/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeTrajets.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AddTrajetSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AddTrajetCompose();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void RechercheSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void RechercheComplexe();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

friend ostream & operator << (ostream & flux, const Catalogue & unCatalogue);

//-------------------------------------------- Constructeurs - destructeur

    Catalogue ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
   char * askVilleArrivee();
   // Mode d'emploi :
   //
   // Contrat :
   //

   char * askVilleDepart();
   // Mode d'emploi :
   //
   // Contrat :
   //

   char * askMoyenTransport();
   // Mode d'emploi :
   //
   // Contrat :
   //

    int rechercheEtape(const char * departTrajet, const char * arriveeFinale, ListeTrajets trajetsPossibles);
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés

   ListeTrajets listeTraj;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
