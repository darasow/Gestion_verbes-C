#ifndef PROGRAME_H_INCLUDED
#define PROGRAME_H_INCLUDED
#include "Menbre.h"
class Programme // une classe qui d'ecrit un programme
{

int jour;
int mois;
int annee;
string lieu;
int heur_debut;
int heur_fin;
int nump;
public:
    Programme(int j = 0, int m = 0, int a = 0, string l = 0, int hd = 0, int hf = 0, int np = 0)
    : jour(j), mois(m), annee(a), lieu(l), heur_debut(hd), heur_fin(hf), nump(np){}
  void affiche()
  {
 position(60, 1); cout << "Programme N°:" << nump << endl;
 position(25, 2); cout << "Date :" << jour << "/" << mois << "/" << annee << endl;
 position(55, 2); cout << "Lieu :" << lieu << endl;
 position(75, 2); cout << "Heure_Debut :" << heur_debut << "h"<< endl;
 position(100,2); cout << "Heure_Fin :" << heur_fin << "h"<< endl;
  }
};

#endif // PROGRAME_H_INCLUDED
