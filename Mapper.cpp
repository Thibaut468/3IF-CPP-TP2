/*************************************************************************
                           Mapper  -  Classe principale de gestion du catalogue
                           et de la demande de trajet - test
                             -------------------
    début                : 19 NOVEMBRE 2019
    copyright            : (C) 2019 par BRANCHEREAU, GRAVEY
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Mapper> (fichier Mapper.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Fonctions publiques

int main()
{

   // CREER UNE CLASSE MENU
   bool end = false;

   Catalogue catalogue = Catalogue();

   catalogue.GetListeTraj().AddTrajetSimple("Lyon","Paris","Bateau");
   catalogue.GetListeTraj().AddTrajetSimple("Marseille","Bordeaux","Avion");
   catalogue.GetListeTraj().AddTrajetSimple("Lyon","Angers","Train");

   while(!end)
   {
      cout << "Menu:" << endl;
      cout << "\t1: Ajouter un trajet simple" << endl;
      cout << "\t2: Ajouter un trajet composé" << endl;
      cout << "\t3: Afficher le catalogue" << endl;
      cout << "\t0: Quitter l'application Mapper" << endl;

      int choix;
      scanf("%d",&choix);

      switch (choix) {
         case 0:
            end=true;
            break;
         case 1:
            break;
         case 2:
            break;
         case 3:
            catalogue.Presenter();
            break;
         default:
            cout << "Saisie du choix incorrect. Recommencer." << endl;
            continue; //Revient au début du menu.
      }
   }

   return EXIT_SUCCESS;
}
