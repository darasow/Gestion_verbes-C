#ifndef MENBRE_H_INCLUDED
#define MENBRE_H_INCLUDED
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include <ctime>
using namespace std;
inline void position(int x, int y,int col = 0)
{
  HANDLE ecran = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD repere;
  repere.X = x;
  repere.Y = y;
  SetConsoleCursorPosition(ecran,repere);


}
inline void back_graound(int col)
{
    HANDLE ecran = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(ecran, col);
}
class Membre // une classe membre qui represente un membre
{
string matricule;
string nom;
string prenom;
int heur_arrive;
int heur_depar;
string pourcentage;
 public:
   Membre(string m = 0, string n = 0, string p = 0, int ha = 0, int hd = 0, string pr = 0)
   : matricule(m), nom(n), prenom(p), heur_arrive(ha), heur_depar(hd), pourcentage(pr){}


  void affiche(int i = 0)// la fonction a un parametre i qui indique que ligne
// il faut afficher les informations
   {
    position(15, 5 + i);    cout <<  matricule;
    position(35, 5 + i);   cout <<  nom ;
    position(55, 5 + i);    cout <<  prenom ;
     position(75, 5 + i);   cout <<  heur_arrive << "h";
      position(100, 5 + i);  cout << heur_depar << "h";
      position(115, 5 + i);  cout <<  pourcentage  << endl;
      cout<<endl;
  }
};

#endif // MENBRE_H_INCLUDED
