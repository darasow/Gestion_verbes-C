#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include "Menbre.h"
#include "Programe.h"
#include "gestion_verbe.h"

void Menbre::affiche(Programe P)
{
cout << "Matricule :" << matricule << endl;
cout << "Nom :" << nom << endl;
cout << "Prenom :" << prenom << endl;
cout << "Heure_Arrive :" << heur_arrive << endl;
cout << "Heure_Depar :" << heur_depar << endl;
cout << "Pourcentage :" << pourcentage << endl;
}

#endif // FONCTION_H_INCLUDED
