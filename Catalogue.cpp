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
#include <cstring>

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

void Catalogue::AddTrajetSimple()
// Algorithme :
//
{
   char * vDepart = askVilleDepart();
   char * vArrivee = askVilleArrivee();
   char * vMoyenTransport = askMoyenTransport();
   TrajetSimple * nouveauTrajet = new TrajetSimple(vDepart,vArrivee,vMoyenTransport);
   listeTraj.AddTrajet(nouveauTrajet);
   delete [] vDepart;
   delete [] vArrivee;
   delete [] vMoyenTransport;
} //----- Fin de addTrajetSimple

void Catalogue::AddTrajetCompose()
// Algorithme :
//
{
  int nbTrajets;
  ListeTrajets* liste=new ListeTrajets();
  cout<<"Nombre de trajets ?"<<endl;
  cin >> nbTrajets;
  cin.ignore();
  while(cin.fail())
  {
      cout << "Erreur, veuillez entrer un entier" <<endl;
      cin.clear();          //on clear les erreurs
      cin.ignore();         // on ignore le prochain caractère
      cin >> nbTrajets;             //on redemande la valeur;
      cin.ignore();
  }

  char vDepartPrincipale[TAILLE_ENTREE_VILLE+1];
  char vArriveePrincipale[TAILLE_ENTREE_VILLE+1];
  char vArriveePrecedent[TAILLE_ENTREE_VILLE+1];

  char * vDepart = askVilleDepart();
  char * vArrivee = askVilleArrivee();
  char * mTransport = askMoyenTransport();

  TrajetSimple* tmpTrajet=new TrajetSimple(vDepart,vArrivee,mTransport);

  liste->AddTrajet(tmpTrajet);
  //vArriveePrecedent=vArrivee;
  strcpy(vArriveePrecedent,vArrivee);
  //vDepartPrincipale=vDepart;
  strcpy(vDepartPrincipale,vDepart);

  for(int i=1;i<nbTrajets;i++)
  {
      delete [] vArrivee;
      delete [] vDepart;
      delete [] mTransport;
      vDepart = askVilleDepart();
      vArrivee = askVilleArrivee();
      mTransport = askMoyenTransport();

      if(strcmp(vDepart,vArriveePrecedent)==0)
      {
        TrajetSimple* tmpTrajet=new TrajetSimple(vDepart,vArrivee,mTransport);
        liste->AddTrajet(tmpTrajet);
        //vArriveePrecedent=vArrivee;
        strcpy(vArriveePrecedent,vArrivee);
      }
      else
      {
        while(strcmp(vDepart,vArriveePrecedent)!=0)
        {
            cout << "Erreur, vous devez repartir de la ville d'étape précédente" <<endl;
            delete [] vArrivee;
            delete [] vDepart;
            delete [] mTransport;
            vDepart = askVilleDepart();
            vArrivee = askVilleArrivee();
            mTransport = askMoyenTransport();
        }

        TrajetSimple* tmpTrajet=new TrajetSimple(vDepart,vArrivee,mTransport);
        liste->AddTrajet(tmpTrajet);
        //vArriveePrecedent=vArrivee;
        strcpy(vArriveePrecedent,vArrivee);
      }
  }

  //vArriveePrincipale=vArrivee;
  strcpy(vArriveePrincipale,vArrivee);

  TrajetCompose* nouveauTrajetCompose=new TrajetCompose(vDepartPrincipale,vArriveePrincipale,liste);
  listeTraj.AddTrajet(nouveauTrajetCompose);

  delete [] vArrivee;
  delete [] vDepart;
  delete [] mTransport;
} //----- Fin de AddTrajetCompose


void Catalogue::RechercheSimple()
// Algorithme :
//
{

   char * vDepart=askVilleDepart();
   char * vArrivee=askVilleArrivee();

   cout << "-- Résultat de la recherche simple entre " << vDepart << " et " << vArrivee << " --" << endl;

   Trajet ** listeTmp = listeTraj.GetListe();
   int nbTrajets = listeTraj.GetNbTrajets();
   for(int i=0;i<nbTrajets;i++)
   {
      if(strcmp(listeTmp[i]->GetVilleDepart(),vDepart)==0 && strcmp(listeTmp[i]->GetVilleArrivee(),vArrivee)==0)
         listeTmp[i]->Affichage();

   }
} //----- Fin de RechercheSimple


void Catalogue::RechercheComplexe()
// Algorithme :
//
{
   char * vDepart=askVilleDepart();
   char * vArrivee=askVilleArrivee();
   ListeTrajets* trajetsPossibles=new ListeTrajets();
   RechercheEtape(vDepart,vArrivee,trajetsPossibles);   // Ne fonctionne pas encore, problème sur la methode Retirer de TrajetSimple
   delete trajetsPossibles;
} //----- Fin de RechercheComplexe

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

char * Catalogue::askVilleArrivee()
// Algorithme :
//
{
   char* ret=new char[TAILLE_ENTREE_VILLE+1];
   cout << "Saisir la ville d'arrivée: " << endl;
   cin.getline(ret,TAILLE_ENTREE_VILLE);
   return ret;
} //----- Fin de AskVilleDepart

char * Catalogue::askVilleDepart()
// Algorithme :
//
{
   char* ret = new char[TAILLE_ENTREE_VILLE+1];
   cout << "Saisir la ville de départ : " << endl;
   cin.getline(ret,TAILLE_ENTREE_VILLE);
   return ret;
} //----- Fin de AskVilleArrivee

char * Catalogue::askMoyenTransport()
// Algorithme :
//
{
   char* ret=new char[TAILLE_ENTREE_MOYEN_TRANSPORT+1];
   cout << "Saisir le moyen de transport : " << endl;
   cin.getline(ret,TAILLE_ENTREE_VILLE);
   return ret;
} //----- Fin de AskMoyenTransport

int Catalogue::RechercheEtape(char * departTrajet, char * arriveeFinale, ListeTrajets* trajetsPossibles)
//Algorithme : Methode recursive
//
{

    ListeTrajets trajets = ListeTrajets(listeTraj);
    Trajet** liste=trajets.GetListe();

    if(strcmp(departTrajet,arriveeFinale)==0) // si ville de départ et d'arrivee sont les mêmes: signifie qu'on à atteint notre destination
    {
        cout<<"liste des trajets possibles"<<endl;
        trajetsPossibles->AffichageTrajets();
        cout<<endl<<endl;
        return 1;
    }
    for(int i=0;i<trajets.GetNbTrajets();i++)
    {
        Trajet* t=liste[i];

        if(strcmp(t->GetVilleDepart(),departTrajet)==0) //si le trajet t auquel on s'intéresse part bien du même point que le noeud ou l'on est actuellement
        {
            int valide=1;

            for(int j=0;j<trajetsPossibles->GetNbTrajets();j++)
            {
                if(strcmp(t->GetVilleArrivee(),trajetsPossibles->GetListe()[j]->GetVilleDepart())==0) //si la ville d'arrivée est déja présente
                {                                                                     //dans les trajets possible en tant que ville de départ
                    valide=0;        //afin de ne pas créer de boucle infinie
                }
            }
            if(valide)
            {
                trajetsPossibles->AddTrajet(t);                                       //On ajoute une arrête à explorer à partir de ce noeud
                RechercheEtape(t->GetVilleArrivee(),arriveeFinale,trajetsPossibles);  //On part explorer cette arrête
                trajetsPossibles->RetirerDernier();                                   //On retire cette arrête pour ne pas l'explorer à partir des autres noeuds
            }
        }
    }

    //delete trajets;
    return 0;
}// Fin de RechercheEtape

//----------------------------------------------------- Méthodes protégées
