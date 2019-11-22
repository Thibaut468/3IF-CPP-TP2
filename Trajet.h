/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 19 NOVEMBRE
    copyright            : (C) 2019 par BRANCHEREAU,GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  virtual void Affichage () const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  char* GetVilleDepart() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

  char* GetVilleArrivee() const;
  // Mode d'emploi :
  //
  // Contrat :
  //

//-------------------------------------------- Constructeurs - destructeur
    Trajet (const char* vDepart,const char* vArrivee);
    // Mode d'emploi :
    //  affecte les valeurs des attributs villes de départ et d'arrivée
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  char* villeDepart;
  char* villeArrivee;

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
