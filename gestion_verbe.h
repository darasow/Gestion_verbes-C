#ifndef GESTION_VERBE_H_INCLUDED
#define GESTION_VERBE_H_INCLUDED
#include "Programe.h"
inline int anneeEnCours()
{
    // date / heure actuelle basée sur le système actuel
   time_t actuel = time(0);
   tm *tme = localtime(&actuel);
   unsigned int annee = (1900 + tme->tm_year);
   // buzard ici on a (1900 + tme->tm_year)
   // le commentaire de la structure nous indique pour recuperer l'annee en cours il faut
   // faire la somme de la valeur retourner par tme->tm_year a 1900
   // Exemple : elle retourne ici 122 et 122 + 1900 cequi fait 2022
   return (annee);
}
inline int moisEnCours()
{
    // date / heure actuelle basée sur le système actuel
    time_t actuel = time(0);
    tm *tme = localtime(&actuel);
    unsigned int mois = (1 + tme->tm_mon); // le commentaire en bas explique pourquoi le (1 + tme->tm_mon)
    // on met parceque la methode retoune le numero du mois-1
   // et nous on veut exactement le numero du mois on met le +1
   return (mois);
}
 inline int jourEnCours()
{
    // date / heure actuelle basée sur le système actuel
   time_t actuel = time(0); // time_t est un type de fini dans (types.h) qui reçoit une valeur qui correspond a un temps de l'ordinateur
    // soit l'heure , minute ,seconde, annee, jour ou mois
    // la fonction time() est une fonction deja developpee elle atemps un pointeur
    // apres plusieur teste c'est 0 qui prend
    // la signature de time est: time_t time(time_t * v)
    // time() retourne une valeur de type time_t
    // donc on vas stocker cela dans une variable time_t que j'ai appeler actuel
   tm *tme = localtime(&actuel);
   //la signature de localtime qui est defini dans (time.h) est : tm* localtime(const time_t* V )
   // tm est une structure pointeur deja developpee et grace a une variable de son type on peut directement
   // acceder au menbre de la structre qui est defini dans (wchar.h)
   /*
   struct tm {
        int tm_sec;      seconds after the minute - [0,59] // seconde
        int tm_min;      minutes after the hour - [0,59] * // minute
        int tm_hour;     hours since midnight - [0,23] * // heure
        int tm_mday;     day of the month - [1,31] * // le numero du jour du mois
        int tm_mon;      months since January - [0,11] * // mois en cours
        int tm_year;     years since 1900  / annee + 1900* // annee en cours
        int tm_wday;     days since Sunday - [0,6] * / numero du jour de la semaine
        int tm_yday;     days since January 1 - [0,365] * / numero du jour dans l'annee
        int tm_isdst;    daylight savings time flag
        };

   */
   // la fonction localtime() retourne un objet qui permet de retourner ce qu'on a besoin
   unsigned int jours = (tme->tm_mday );// jour
   return (jours);
}
inline int heurActuel()
{
time_t actuel = time(0);
tm *tme = localtime(&actuel);
unsigned int heur = (tme->tm_hour);
return heur;
}
inline int minuteActuel()
{
time_t actuel = time(0);
tm *tme = localtime(&actuel);
unsigned int minute = (tme->tm_min);
return minute;
}

inline void heure_date()
{
position(1, 33); cout << "Fichier Compiler:" <<__FILE__;// affiche le chemin d'acces du fichier compiler
position(1, 34); cout << "Heure de compilation:" <<__TIME__;// affiche l'heure de compilation
position(1, 35); cout << "Date de compilation:" <<__DATE__;// affiche la date de compilation
position(3, 30 ); cout << jourEnCours() << "/" << moisEnCours() << "/" << anneeEnCours(); // date du jour
position(3, 31); cout << heurActuel() << "h" << ":" << minuteActuel() << "mn" << endl;// heure en cours

}

inline void conjugue(string, string, string, string,string);// le prototype de la fonction pour que le compilateur la voi
inline bool iregulier(string);
inline void gestion_verbe()
{
             heure_date();
             string verbe;
      position(40, 1); cout << "Verbe :" ;
      position(49, 1); getline(cin, verbe);
      string radical_pronominal;string rad_pronominal;string verbe_pronominal;
      string radical = string(verbe, 0, verbe.length()-2);
      string rad = string(radical, radical.length()-1, 1);
      string sifixe = string(verbe, verbe.length()-2, 2);
      string pronominal_1 = string(verbe, 0, 3); // recupere les trois premier caractere que user a saisi
                                        // Exemple: se parler, le trois premier caractere sont "se "
      string pronominal_2 = string(verbe, 0, 2);// recupere les deux premier caractere que user a saisi
                                        // Exemple: s'arranger, le deux premier caractere sont "s'"
      if(pronominal_1 == "se ") // teste si c'est "se "
        {
        verbe_pronominal = string(verbe, 3, verbe.length()); // on recupere le verbe
        // s'il a saisi < se parler> le verbe est "parler"
        // on commence de copier a la position 3
        radical_pronominal = string(verbe_pronominal, 0, verbe_pronominal.length()-2 );
        rad_pronominal = string(radical_pronominal, radical_pronominal.length()-1, 1);
      conjugue(verbe_pronominal, radical_pronominal, sifixe, rad_pronominal, pronominal_1);// on appel la focntion conjugue et on emvoi les parametre
                                     // le dernier parametre c'est pour permetre de savoir dans la fonction conjugue
                                     // s'il sagi d'un verbe pronominal
        } else if(pronominal_2 == "s'")
        {
        verbe_pronominal = string(verbe, 2, verbe.length());// on recupere le verbe
        // s'il a saisi < s'angager> le verbe est "angager"
        // on commence de copier a la position 2
        radical_pronominal = string(verbe_pronominal, 0, verbe_pronominal.length()-2 );
        rad_pronominal = string(radical_pronominal, radical_pronominal.length()-1, 1);
       conjugue(verbe_pronominal, radical_pronominal, sifixe, rad_pronominal, pronominal_2);
       // en haut on a emvoyer pronominal_1 et ici on a emvoyer pronominal_2
       // mais dans la fonction conjugue que sa soit "se " ou "s'" tout se conjugue de la meme maniere donc il s'agit
       // que l'une des condition soit verifier
       // mais d'autre diront que c'est une repetion , c'est pas une repetition c'est parceque la recuperation
       // des parametre ne se fait de la meme maniere avec "se " et "s'"
        } else conjugue(verbe, radical, sifixe, rad, pronominal_1); // si user a saisi le verbe sans "se " ni "s'"

}
void entete()
{
    position(15, 4); cout << "MATRICULE";
    position(35, 4); cout << "NOM";
    position(55, 4); cout << "PRENOM";
    position(75, 4); cout << "HEURE-ARRIVE";
    position(100, 4); cout << "HEURE-DEPART";
    position(115, 4); cout << "POURCENTAGE" << endl;

}
inline void fiche_de_rencontre()
{
      entete();heure_date();
    Programme P1(26, 05, 2022, "UBO", 10, 17, 1);
    Membre M1P1("B1121 6MI", "Sow", "Mamadou Dara", 10, 17, "90%");
    Membre M2P1("B1121 55GI", "Bah", "Abdoulaye", 0, 0, "Malade");
    Membre M3P1("B1121 13GI", "Barry", "Kadiatou", 10, 17, "50%");
    Membre M4P1("B1121 18GI", "Mamy", "Daniel", 0, 0, "Chaumé");
    Membre M5P1("B1121 5MI", "Diallo", "Hadiatou", 10, 17, "40%");
    Membre M6P1("B1121 8MI", "Diallo", "Aissatou", 10, 16, "30%");
    P1.affiche();
    M1P1.affiche(0);
    M2P1.affiche(1);
    M3P1.affiche(2);
    M4P1.affiche(3);
    M5P1.affiche(4);
    M6P1.affiche(5);
    system("pause");
    system("cls");

    entete();heure_date();
    Programme P2(30, 05, 2022, "UBO", 10, 17, 2);
    Membre M1P2("B1121 6MI", "Sow", "Mamadou Dara", 10, 17, "90%");
    Membre M2P2("B1121 55GI", "Bah", "Abdoulaye", 10, 17, "55%");
    Membre M3P2("B1121 13GI", "Barry", "Kadiatou", 10, 17, "60%");
    Membre M4P2("B1121 18GI", "Mamy", "Daniel", 10, 17, "45%");
    Membre M5P2("B1121 5MI", "Diallo", "Hadiatou", 0, 0, "Malade");
    Membre M6P2("B1121 8MI", "Diallo", "Aissatou", 10, 17, "40%");
    P2.affiche();
    M1P2.affiche(0);
    M2P2.affiche(1);
    M3P2.affiche(2);
    M4P2.affiche(3);
    M5P2.affiche(4);
    M6P2.affiche(5);
        system("pause");
        system("cls");
     entete();heure_date();
    Programme P3(01, 06, 2022, "UBO", 14, 17, 3);
    Membre M1P3("B1121 6MI", "Sow", "Mamadou Dara", 14, 17, "90%");
    Membre M2P3("B1121 55GI", "Bah", "Abdoulaye", 14, 17, "55%");
    Membre M3P3("B1121 13GI", "Barry", "Kadiatou", 14, 17, "60%");
    Membre M4P3("B1121 18GI", "Mamy", "Daniel", 0, 0, "Chaumé");
    Membre M5P3("B1121 5MI", "Diallo", "Hadiatou", 0, 0, "Malade");
    Membre M6P3("B1121 8MI", "Diallo", "Aissatou", 0, 0, "Chaumé");
    P3.affiche();
    M1P3.affiche(0);
    M2P3.affiche(1);
    M3P3.affiche(2);
    M4P3.affiche(3);
    M5P3.affiche(4);
    M6P3.affiche(5);
    system("pause");
    system("cls");

    entete();heure_date();
    Programme P4(03, 06, 2022, "UBO", 14, 17, 4);
    Membre M1P4("B1121 6MI", "Sow", "Mamadou Dara", 14, 17, "90%");
    Membre M2P4("B1121 55GI", "Bah", "Abdoulaye", 14, 17, "55%");
    Membre M3P4("B1121 13GI", "Barry", "Kadiatou", 14, 17, "60%");
    Membre M4P4("B1121 18GI", "Mamy", "Daniel", 0, 0, "Urgence");
    Membre M5P4("B1121 5MI", "Diallo", "Hadiatou", 0, 0, "Malade");
    Membre M6P4("B1121 8MI", "Diallo", "Aissatou", 14, 17, "40%");
    P4.affiche();
    M1P4.affiche(0);
    M2P4.affiche(1);
    M3P4.affiche(2);
    M4P4.affiche(3);
    M5P4.affiche(4);
    M6P4.affiche(5);
    system("pause");
    system("cls");
}
inline void presentation()
{
  string titre = "LOGICIEL DE CONJUGUAISON";
  string presentation2 = "REALISE PAR : ";
  string auteur1 = "1-MAMADOU DARA SOW: B1121 6MI";
  string auteur2 = "2-KADIATOU BARRY: B1121 13GI";
  string auteur3 = "3-Aissatou Diallo: B1121 8MI";
  string auteur4 = "4-Hadiatou Diallo: B1121 5MI";
  string auteur5 = "5-Abdoulaye Bah: B1121 55GI";
  string auteur6 = "6-Daniel Mamy: B1121 18GI";
   int t_titre = titre.length();
   int t_presentation2 = presentation2.length();
   int t_auteur1 = auteur1.length();
   int t_auteur2 = auteur2.length();
   int t_auteur3 = auteur3.length();
   int t_auteur4 = auteur4.length();
   int t_auteur5 = auteur5.length();
   int t_auteur6 = auteur6.length();
   heure_date();
    for(int i(0) ; i < t_titre ; i++)
    {
    position(i+25,5); cout << titre[i];
    Sleep(100);
    }
     for(int i(0) ; i < t_presentation2 ; i++)
    {
    position(i+25,7); cout << presentation2[i];
    Sleep(100);

    }
      for(int i(0) ; i < t_auteur1 ; i++)
    {
    position(i+25,9); cout << auteur1[i];
    Sleep(100);

    }
      for(int i(0) ; i <t_auteur2 ; i++)
    {
    position(i+25,10); cout << auteur2[i];
    Sleep(100);
    }
    for(int i(0) ; i <t_auteur3 ; i++)
    {
    position(i+25,11); cout << auteur3[i];
    Sleep(100);
    }
    for(int i(0) ; i <t_auteur4 ; i++)
    {
    position(i+25,12); cout << auteur4[i];
    Sleep(100);
    }
    for(int i(0) ; i <t_auteur5 ; i++)
    {
    position(i+25,13); cout << auteur5[i];
    Sleep(100);
    }
    for(int i(0) ; i <t_auteur6 ; i++)
    {
    position(i+25,14); cout << auteur6[i];
    Sleep(100);
    }
    getch();
    system("cls");
}
inline bool verif_sifixe(string sifixe, string verbe)
{
return ((sifixe == "er" or sifixe == "ir") and !iregulier(verbe));
}

inline bool iregulier(string verbe)
{
 string verbe_iregulier[14] =
{
"tenir", "abstenir", "appartenir", "contenir", "détenir", "aller", "pouvoir", "vouloir",
"entretenir", "maintenir", "obtenir", "retenir", "soutenir", "venir"
};
for(int i(0) ; i < 14 ; i++) if(verbe == verbe_iregulier[i]) return true;
return false;
}

inline bool impersonnel(string verbe)
{
string verbe_impersonel[25]=
{
"barder", "agir", "boumer","brouillasser","bruiner","brumer","brumasser",
"crachiner","dracher","glacer","gouttiner","grêler","grésiller","neiger",
"neigeoter","pleuvasser","pleuviner","pleuvioter","pleuvoter","pluviner",
"reneiger","urger","vaser","venter","verglacer"
};
  for(int i(0); i < 25 ; i++) if (verbe_impersonel[i] == verbe) return true;
  return false;
}
inline void temps_simple(void)
{

                    position(3,2) ; cout << "Present:";
                    position(27,2) ;   cout << "Imparfait:";
                    position(55,2) ;   cout << "passé simple:";
                    position(80,2) ;  cout << "Futur simple:";
}
inline void temps_compose(void)
{
                    position(3,10) ; cout << "Passé Compose:";
                    position(27,10) ;   cout << "Plus-que-parfait:";
                    position(55,10) ;   cout << "passé Anterieur:";
                     position(80,10) ;  cout << "Futur Anterieur:";

}
inline bool pronominal(string verbe)
{
string pronominal_verbe[45] =
{
 "attabler","bidonner","biturer", "blotir", "carapater",
"chamailler", "castagner", "désister", "desister", "enamourer", "enfuir",
"fier", "gargariger", "gendarmer", "gominer", "gourer", "grumeler", "insurger",
"lamenter", "lignifier", "magner", "marrer", "mécompter", "méfier",
"motter", "mutiner", "parjurer", "pavaner", "pistacher", "poiler", "pommeler",
"pourprer", "prosterner", "raviser", "lebeler", "mecompter", "mefier", "récrier",
"recrier", "recroqueviller", "rengorger", "revencher", "cuiter", "débrailler",
"debrailler"
};
for(int i(0) ; i < 45 ; i++) if(verbe == pronominal_verbe[i]) return true;
return false;
}
inline bool aux_etre(string verbe)
{
 string use_aux_etre[14] =
 {
 "entrer", "monter", "tomber", "arriver", "rester", "retourner", "passer",
 "rentrer", "bauger", "biler", "décéder", "deceder", "rester", "retomber"
};
   for(int i(0) ; i < 14; i++) if(use_aux_etre[i] == verbe) return true;
   return false;

}

inline void conjugue(string verbe, string radical, string sifixe, string rad, string prnominal = 0)
 {
if(verif_sifixe(sifixe, verbe)) // on verifi si c'est un verbe du premier ou deuxieme groupe
                               // excepter des irreguliers
    {
 string personne[6] = {"je", "Tu","Il", "Nous", "Vous", "Ils/Elles"};
 string present1[6] = {"e", "es", "e", "ons", "ez", "ent"}; // present 1er groupe
 string present2[6] = {"is", "is", "it", "issons", "issez", "issent"};// premier 2em groupe
 string imparfait1[6] = {"ais", "ais", "ait", "ions", "iez", "aient"};// imparfait 1er groupe
 string imparfait2[6] = {"issais", "issais", "issait", "issions", "issiez", "issaient"};// imparfait 2em groupe
 string passe_simple1[6] = {"ai", "as", "a", "âmes", "âtes", "èrent"};// passe simple 1er
 string passe_simple2[6] = {"is", "is", "it", "îmes", "îtes", "îrent"}; // passe simple 2em grope
 string  future_simple_1_2[6] = {"ai", "a", "a" ,"ons", "ez", "ont"};// future simple 1er et 2em groupe
 string terminaison_auxEtre_4tmpCompose1[6] = {"é(e)", "é(e)","é(e)","é(e)s","é(e)s","é(e)s"} ; // terminaison des verbe du 1er groupe avec l'auxilliare etre avec les 4 temps compose
 string terminaison_auxAvoir_4tmpCompose1[6] = {"é", "é","é","é","é","é"} ;// terminaison des verbe du 1er groupe avec l'auxilliare avoir avec les 4 temps compose
 string terminaison_auxAvoir_4tmpCompose2[6] = {"i", "i","i","i","i","i"} ;// terminaison des verbe du 2eme groupe avec l'auxilliare avoir avec les 4 temps compose
 string use_aux_etre_passe_compose1[6] = {"suis", "es", "est","sommes", "êtes","sont"}; // l'utilisation de l'auxilliaire etre au passe compose des verbe du 1er groupe
 string use_aux_avoir_passe_compose1_2[6] = {"ai", "as", "a","avons", "avez","ont"};// l'utilisation de l'auxilliaire avoir au passe compose des verbe du 1er et 2em groupe
 string use_aux_etre_plusqparfait1[6] = {"étais", "étais", "était", "étions", "étiez", "étaient"};// l'utilisation de l'auxilliaire etre au plus-que-parfait des verbe du 1er groupe
 string use_aux_avoir_plusque_parfait1_2[6] = {"avais", "avais", "avait", "avions", "aviez", "avaient"};// l'utilisation de l'auxilliaire avoir au plus-que-parfait des verbe du 1er et 2em groupe
 string use_aux_etre_passenterieur1[6] = {"fus", "fus", "fut", "fûmes", "fûtes", "furent"};// l'utilisation de l'auxilliaire etre au passe anterieur des verbe du 1er groupe
 string use_aux_avoir_passeAnterieur1_2[6] = {"eus", "eus", "eut", "eûmes", "eûtes", "eurent"};// l'utilisation de l'auxilliaire avoir au passe anterieur des verbe du 1er et 2em groupe
 string use_aux_etre_futureAnterieur1[6] = {"serai", "seras", "sera", "serons", "serez", "seront"};// l'utilisation de l'auxilliaire etre au future anterieur des verbe du 1er groupe
 string use_aux_avoir_futureAnterieur1_2[6] = {"aurai", "auras", "aura", "aurons", "aurez", "auront"};// l'utilisation de l'auxilliaire avoir au future anterieur des verbe du 1er et 2em groupe
 char voyel[11]={'a','â','é','à','è','e','i','ê','o','u','y'};
 for(int i(0); i < 11 ; i++) if (radical[0] == voyel[i]) personne[0] = "j'"; // gestion des voyelles
  if(pronominal(verbe) or prnominal == "se " or prnominal == "s'") // si le verbe est pronominal ou si l'utilisateur saisi "se "
                                                                // comme (se parler) ou bien on teste si c'est "s'" comme (s'introduir)
   {
                personne[0] = "je";
        string use_pronominal_4tmpSimple[6] = {"me", "te", "se", "nous", "vous", "se"};
       for(int i(0); i < 11 ; i++) if (radical[0] == voyel[i])//si le verbe commence par une voyelle on remplace le (e) par (')
        {
        use_pronominal_4tmpSimple[0] = "m'";
        use_pronominal_4tmpSimple[1] = "t'";
        use_pronominal_4tmpSimple[2] = "s'";
        use_pronominal_4tmpSimple[5] = "s'";
        }
        string use_pronominal_passeCompose[6] = {"me suis", "t'es", "s'est", "nous sommes", "vous êtes","se sont"}; // l'utilisation de la forme pronominal au passe compose
        string use_pronominal_plus_que_parfait[6] = {"m'étais", "t'étais", "s'était", "nous étions", "vous étiez", "s'étaient"};// l'utilisation de la forme pronominal au plus-que-parfait
        string use_pronominal_passe_anterieur[6] = {"me fus", "te fus", "se fut", "nous fûmes", "vous fûtes", "se furent" };// l'utilisation de la forme pronominal au passe anterieur
        string use_pronominal_futur_anterieur[6] = {"me serai", "te seras", "se sera", "nous serons", "vous serez", "seront"};// l'utilisation de la forme pronominal au future anterieur

            if(sifixe == "er") // on teste si c'est du 1er groupe
                { // les verbe irreguliers dans les 4 temps compose  se terminent avec la meme
                    // terminaison des verbe du 1er groupe avec l'auxilliare etre
                    // sauf que les  3 derniere personne il y a (s)
                    temps_simple();// les quatre temps simple
                    terminaison_auxEtre_4tmpCompose1[3] = "és";
                    terminaison_auxEtre_4tmpCompose1[4] = "és";
                    terminaison_auxEtre_4tmpCompose1[5] = "és";

            if(rad == "G" or rad == "g") // on teste si le premier caractre est (g ou G)
             {
           present1[3] = "eons";
           imparfait1[0] = "eais";
           imparfait1[1] = "eais";
           imparfait1[2] = "eait";
           imparfait1[5] = "eaient";
           passe_simple1[0] = "eai";
           passe_simple1[1] = "eas";
           passe_simple1[2] = "ea";
           passe_simple1[3] = "eâmes";
           passe_simple1[4] = "eâtes";
        for(int i(0); i < 6 ; i++)
            {
            position(3,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << radical << present1[i];
            position(27,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << radical << imparfait1[i];
            position(55,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << radical << passe_simple1[i];
            position(80,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << verbe << future_simple_1_2[i];

            } // 4 temps simple
            /*
            Exemple: s'angager
            radical: angag

    Present:                Imparfait:                  passé simple:            Futur simple:
   je m' angage            je m' angageais             je m' angageai           je m' angagerai
   Tu t' angages           Tu t' angageais             Tu t' angageas           Tu t' angagera
   Il s' angage            Il s' angageait             Il s' angagea            Il s' angagera
   Nous nous angageons     Nous nous angagions         Nous nous angageâmes     Nous nous angagerons
   Vous vous angagez       Vous vous angagiez          Vous vous angageâtes     Vous vous angagerez
   Ils/Elles s' angagent   Ils/Elles s' angageaient    Ils/Elles s' angagèrent  Ils/Elles s' angageront

            */


        } else if (rad == "c" or rad == "C") // si le dernier caractere du radical est (c ou C)
                {
               string radical_c = string(radical,0,radical.length()-1); // on coupe le dernier caractere
               string presentc[6] = {"ce", "ces", "ce", "çons", "cez", "cent"};
               string imparfaitc[6] = {"çais", "çais", "çait", "cions", "ciez", "çaient"};
               string pastc[6] = {"çai", "ças", "ça", "çâmes", "çâtes", "cèrent"};
               for(int i(0) ; i < 6 ; i++)
                {
               position(3,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << radical_c << presentc[i];
               position(27,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << radical_c << imparfaitc[i];
               position(55,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << radical_c << pastc[i];
               position(80,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << verbe << future_simple_1_2[i];
               }
               // Exemple : se placer
               // radical : plac
               /*

    Present:                Imparfait:                  passé simple:            Futur simple:
   je me place             je me plaçais               je me plaçai             je me placerai
   Tu te places            Tu te plaçais               Tu te plaças             Tu te placera
   Il se place             Il se plaçait               Il se plaça              Il se placera
   Nous nous plaçons       Nous nous placions          Nous nous plaçâmes       Nous nous placerons
   Vous vous placez        Vous vous placiez           Vous vous plaçâtes       Vous vous placerez
   Ils/Elles se placent    Ils/Elles se plaçaient      Ils/Elles se placèrent   Ils/Elles se placeront

    */ } else for(int i(0) ; i < 6 ; i++)
                        {
                        position(3,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << radical << present1[i];
                        position(27,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << radical << imparfait1[i];
                        position(55,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << radical  << passe_simple1[i];
                        position(80,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << verbe << future_simple_1_2[i];

                        }

                   temps_compose();
                     for(int i(0) ; i < 6 ; i++)
                     {
                      position(3,i+11); cout << personne[i] << " " << use_pronominal_passeCompose[i] << " " << radical << terminaison_auxEtre_4tmpCompose1[i];
                      position(27,i+11); cout << personne[i] << " " << use_pronominal_plus_que_parfait[i] << " " <<radical << terminaison_auxEtre_4tmpCompose1[i];
                      position(55,i+11);  cout << personne[i] << " " << use_pronominal_passe_anterieur[i] << " " << radical << terminaison_auxEtre_4tmpCompose1[i];
                      position(80,i+11); cout << personne[i] << " " << use_pronominal_futur_anterieur[i]<< " " << radical << terminaison_auxEtre_4tmpCompose1[i];
                     }

                     /*
     Passé Compose:          Plus-que-parfait:           passé Anterieur:           Futur Anterieur:
   je me suis placé(e)       je m'étais placé(e)         je me fus placé(e)         je me serai placé(e)
   Tu t'es placé(e)          Tu t'étais placé(e)         Tu te fus placé(e)         Tu te seras placé(e)
   Il s'est placé(e)         Il s'était placé(e)         Il se fut placé(e)         Il se sera placé(e)
   Nous nous sommes placés   Nous nous étions placés     Nous nous fûmes placés     Nous nous serons placés
   Vous vous êtes placés     Vous vous étiez placés      Vous vous fûtes placés     Vous vous serez placés
   Ils/Elles se sont placés  Ils/Elles s'étaient placés  Ils/Elles se furent placé  Ils/Elles seront placés

                     */

                }// premier groupe
            else // deuxieme groupe
                {
                     temps_simple();
                     terminaison_auxAvoir_4tmpCompose2[3] = "is"; //
                     terminaison_auxAvoir_4tmpCompose2[4] = "is";
                     terminaison_auxAvoir_4tmpCompose2[5] = "is";
                       for(int i(0) ; i < 6 ; i++)
                        {
                        position(3,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << radical << present2[i];
                        position(27,i+3); cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << radical << imparfait2[i];
                        position(55,i+3);cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << radical << passe_simple2[i];
                        position(80,i+3);cout << personne[i] << " " << use_pronominal_4tmpSimple[i] << " " << verbe << future_simple_1_2[i];

                        }
                        // Exemple: s'introduir
                        /*
                Present:                  Imparfait:                  passé simple:              Futur simple:
               je m' introduis           je m' introduissais           je m' introduis           je m' introduirai
               Tu t' introduis           Tu t' introduissais           Tu t' introduis           Tu t' introduira
               Il s' introduit           Il s' introduissait           Il s' introduit           Il s' introduira
               Nous nous introduissons   Nous nous introduissions      Nous nous introduîmes     Nous nous introduirons
               Vous vous introduissez    Vous vous introduissiez       Vous vous introduîtes     Vous vous introduirez
               Ils/Elles s' introduisse  Ils/Elles s' introduissaient  Ils/Elles s' introduîrent  Ils/Elles s' introduiront

                        */

                   temps_compose();
                    for(int i(0) ; i < 6 ; i++)
                    {
                      position(3,i+11); cout << personne[i] << " " << use_pronominal_passeCompose[i] << " " << radical <<  terminaison_auxAvoir_4tmpCompose2[i];
                      position(27,i+11);cout << personne[i] << " " << use_pronominal_plus_que_parfait[i] << " " << radical << terminaison_auxAvoir_4tmpCompose2[i];
                      position(55,i+11); cout << personne[i] << " " << use_pronominal_passe_anterieur[i] << " " << radical << terminaison_auxAvoir_4tmpCompose2[i];
                      position(80,i+11);cout << personne[i] << " " << use_pronominal_futur_anterieur[i] << " " << radical << terminaison_auxAvoir_4tmpCompose2[i];

                    }
                    /*

      Present:                  Imparfait:                    passé simple:              Futur simple:
     je m' introduis           je m' introduissais           je m' introduis            je m' introduirai
     Tu t' introduis           Tu t' introduissais           Tu t' introduis            Tu t' introduira
     Il s' introduit           Il s' introduissait           Il s' introduit            Il s' introduira
     Nous nous introduissons   Nous nous introduissions      Nous nous introduîmes      Nous nous introduirons
     Vous vous introduissez    Vous vous introduissiez       Vous vous introduîtes      Vous vous introduirez
     Ils/Elles s' introduisse  Ils/Elles s' introduissaient  Ils/Elles s' introduîrent  Ils/Elles s' introduiront

                   */
             }// deuxieme groupe
            }// verbes pronominaux

   else if(!impersonnel(verbe)) // verbe non impersonnel
    {
      if(sifixe == "er") // verbe non impersonnel du 1er groupe
        {
            temps_simple();
         if(rad == "G" or rad == "g")
        {
           present1[3] = "eons";
           imparfait1[0] = "eais";
           imparfait1[1] = "eais";
           imparfait1[2] = "eait";
           imparfait1[5] = "eaient";
           passe_simple1[0] = "eai";
           passe_simple1[1] = "eas";
           passe_simple1[2] = "ea";
           passe_simple1[3] = "eâmes";
           passe_simple1[4] = "eâtes";
        for(int i(0); i < 6 ; i++)
            {
            position(3,i+3);  cout<<personne[i]<<" "<<radical<<present1[i] ;
            position(27,i+3);  cout<<personne[i]<<" "<<radical<<imparfait1[i]  ;
            position(55,i+3);  cout<<personne[i]<<" "<<radical<<passe_simple1[i]  ;
            position(80,i+3);  cout<<personne[i]<<" "<<verbe<<future_simple_1_2[i]  ;

            }

        }
        else if (rad == "c" or rad == "C")
                {
               string radical_c = string(radical,0,radical.length()-1);
               string presentc[6] = {"ce", "ces", "ce", "çons", "cez", "cent"};
               string imparfaitc[6] = {"çais", "çais", "çait", "cions", "ciez", "çaient"};
               string pastc[6] = {"çai", "ças", "ça", "çâmes", "çâtes", "cèrent"};
               for(int i(0) ; i < 6 ; i++)
                {
               position(3,i+3); cout << personne[i] << " " << radical_c << presentc[i] ;
               position(27,i+3); cout << personne[i] << " " << radical_c << imparfaitc[i] ;
               position(55,i+3); cout << personne[i] << " " << radical_c << pastc[i] ;
               position(80,i+3); cout << personne[i] << " " << verbe << future_simple_1_2[i] ;
               }

              } else for(int i(0); i < 6 ; i++)
            {
            position(3,i+3);  cout<<personne[i]<<" "<<radical<<present1[i] ;
            position(27,i+3);  cout<<personne[i]<<" "<<radical<<imparfait1[i]  ;
            position(55,i+3);  cout<<personne[i]<<" "<<radical<<passe_simple1[i]  ;
            position(80,i+3);  cout<<personne[i]<<" "<<verbe<<future_simple_1_2[i]  ;

            } // 4 temps simple
            // Exemple: jouer
            // radical: jou
            /*

           Present:                Imparfait:                  passé simple:            Futur simple:
           je joue                 je jouais                   je jouai                 je jouerai
           Tu joues                Tu jouais                   Tu jouas                 Tu jouera
           Il joue                 Il jouait                   Il joua                  Il jouera
           Nous jouons             Nous jouions                Nous jouâmes             Nous jouerons
           Vous jouez              Vous jouiez                 Vous jouâtes             Vous jouerez
           Ils/Elles jouent        Ils/Elles jouaient          Ils/Elles jouèrent       Ils/Elles joueront

            */


            cout <<endl;
            temps_compose();
           if(aux_etre(verbe))// les quatre temps compose des verbe avec l'auxilliaire etre
                {

                for(int i(0) ; i < 6 ; i++)
                {
              position(3,i+11);     cout << personne[i] <<" " << use_aux_etre_passe_compose1[i] << " " << radical << terminaison_auxEtre_4tmpCompose1[i] ;
              personne[0] = "j'";
              position(27,i+11);    cout << personne[i] << " " << use_aux_etre_plusqparfait1[i]<< " " << radical << terminaison_auxEtre_4tmpCompose1[i];
              personne[0] = "je";
              position(55,i+11);    cout << personne[i] << " " << use_aux_etre_passenterieur1[i]<< " " << radical << terminaison_auxEtre_4tmpCompose1[i] ;
              position(80,i+11);    cout << personne[i] << " " << use_aux_etre_futureAnterieur1[i]<< " " << radical << terminaison_auxEtre_4tmpCompose1[i] ;

                }
                /* Exemple: monter
                Passé Compose:            Plus-que-parfait:             passé Anterieur:           Futur Anterieur:
               je suis monté(e)          j' étais monté(e)             je fus monté(e)            je serai monté(e)
               Tu es monté(e)            Tu étais monté(e)             Tu fus monté(e)            Tu seras monté(e)
               Il est monté(e)           Il était monté(e)             Il fut monté(e)            Il sera monté(e)
               Nous sommes monté(e)s     Nous étions monté(e)s         Nous fûmes monté(e)s       Nous serons monté(e)s
               Vous êtes monté(e)s       Vous étiez monté(e)s          Vous fûtes monté(e)s       Vous serez monté(e)s
               Ils/Elles sont monté(e)  sIls/Elles étaient monté(e)s   Ils/Elles furent monté(e)  Ils/Elles seront monté(e)s
               */
                }else
                {
                    // 4 temps compose de l'oxiliaire avoir
                    personne[0] = "j'";
                for(int i(0) ; i < 6 ; i++)
                {
              position(3,i+11);     cout << personne[i] <<" " << use_aux_avoir_passe_compose1_2[i] << " " << radical << terminaison_auxAvoir_4tmpCompose1[i] ;
              position(27,i+11);    cout << personne[i] << " " << use_aux_avoir_plusque_parfait1_2[i]<< " " << radical << terminaison_auxAvoir_4tmpCompose1[i];
              position(55,i+11);    cout << personne[i] << " " << use_aux_avoir_passeAnterieur1_2[i]<< " " << radical << terminaison_auxAvoir_4tmpCompose1[i] ;
              position(80,i+11);    cout << personne[i] << " " << use_aux_avoir_futureAnterieur1_2[i]<< " " << radical << terminaison_auxAvoir_4tmpCompose1[i] ;

                }
                /*
                Exemple: porter
               Passé Compose:          Plus-que-parfait:           passé Anterieur:         Futur Anterieur:
               j' ai porté             j' avais porté              j' eus porté             j' aurai porté
               Tu as porté             Tu avais porté              Tu eus porté             Tu auras porté
               Il a porté              Il avait porté              Il eut porté             Il aura porté
               Nous avons porté        Nous avions porté           Nous eûmes porté         Nous aurons porté
               Vous avez porté         Vous aviez porté            Vous eûtes porté         Vous aurez porté
               Ils/Elles ont porté     Ils/Elles avaient porté     Ils/Elles eurent porté   Ils/Elles auront porté
                */

                }// auxiliaire avoir
        }// verbe premier groupe non impersonnel
        else if(sifixe == "ir")
        {
        temps_simple();
            for(int i(0); i < 6 ; i++)
            {
            position(3,i+3); cout << personne[i] << " " << radical << present2[i] ;
            position(27,i+3); cout << personne[i] << " " << radical << imparfait2[i] ;
            position(55,i+3);cout << personne[i]  << " " << radical <<passe_simple2[i];
            position(80,i+3); cout << personne[i] << " " << verbe << future_simple_1_2[i] ;

            }
            /*Exemple: finir
               Present:                Imparfait:                  passé simple:            Futur simple:
               je finis                je finissais                je finis                 je finirai
               Tu finis                Tu finissais                Tu finis                 Tu finira
               Il finit                Il finissait                Il finit                 Il finira
               Nous finissons          Nous finissions             Nous finîmes             Nous finirons
               Vous finissez           Vous finissiez              Vous finîtes             Vous finirez
               Ils/Elles finissent     Ils/Elles finissaient       Ils/Elles finîrent       Ils/Elles finiront

            */
                cout << endl;
                   temps_compose();
                    personne[0] = "j'";
                     for(int i(0) ; i < 6 ; i++)
                    {
                 //cout << endl;
              position(3,i+11);  cout << personne[i] << " " << use_aux_avoir_passe_compose1_2[i] << " " << radical <<  terminaison_auxAvoir_4tmpCompose2[i] ;
              position(27,i+11); cout << personne[i] << " " << use_aux_avoir_plusque_parfait1_2[i] << " " << radical << terminaison_auxAvoir_4tmpCompose2[i] ;
              position(55,i+11); cout << personne[i] << " " << use_aux_avoir_passeAnterieur1_2[i] << " " << radical << terminaison_auxAvoir_4tmpCompose2[i];
              position(80,i+11); cout << personne[i] << " " << use_aux_avoir_futureAnterieur1_2[i] << " " << radical <<terminaison_auxAvoir_4tmpCompose2[i];

                    }
                    /*
              Passé Compose:          Plus-que-parfait:           passé Anterieur:         Futur Anterieur:
               j' ai fini              j' avais fini               j' eus fini              j' aurai fini
               Tu as fini              Tu avais fini               Tu eus fini              Tu auras fini
               Il a fini               Il avait fini               Il eut fini              Il aura fini
               Nous avons fini         Nous avions fini            Nous eûmes fini          Nous aurons fini
               Vous avez fini          Vous aviez fini             Vous eûtes fini          Vous aurez fini
               Ils/Elles ont fini      Ils/Elles avaient fini      Ils/Elles eurent fini    Ils/Elles auront fini

                    */

        }// verbe 2em groupe
    }// verbe non impersonnel
    else if(sifixe == "er" ) // verbe impersonnel du premier groupe
    {
                    temps_simple();
            position(3,4); cout << personne[2] << " " << radical << present1[2];
            position(27,4);cout << personne[2] << " " << radical << imparfait1[2];
            position(55,4);cout << personne[2] << " " << radical << passe_simple1[2];
            position(80,4);cout << personne[2] << " " << verbe << future_simple_1_2[2];
            /* Exemple: boumer
               Present:                Imparfait:                  passé simple:            Futur simple:

               Il boume                Il boumait                  Il bouma                 Il boumera

            */
                    temps_compose();
              position(3,8); cout << personne[2] << " " <<use_aux_avoir_passe_compose1_2[2] << " " << radical << terminaison_auxEtre_4tmpCompose1[2];
              position(27,8);cout << personne[2] << " " << use_aux_avoir_plusque_parfait1_2[2] << " " << radical << terminaison_auxEtre_4tmpCompose1[2];
              position(55,8);cout << personne[2] << " " << use_aux_avoir_passeAnterieur1_2[2] << " " << radical << terminaison_auxEtre_4tmpCompose1[2];
              position(80,8); cout << personne[2] << " " << use_aux_avoir_futureAnterieur1_2[2] << " " <<radical << terminaison_auxEtre_4tmpCompose1[2];
              /*
     Passé Compose:          Plus-que-parfait:           passé Anterieur:         Futur Anterieur:

     Il a boumé(e)           Il avait boumé(e)           Il eut boumé(e)          Il aura boumé(e)
    */

      }else // verbe impersonnel du deuxieme groupe
      {
                temps_simple();
          position(3, 4); cout << personne[2] << " " << radical << present2[2];
          position(27, 4); cout << personne[2] << " " << radical  << imparfait2[2];
          position(55, 4); cout << personne[2] << " " << radical  << passe_simple2[2];
          position(80, 4); cout << personne[2] << " " << radical << future_simple_1_2[2];
           temps_compose();
          position(3, 8); cout << personne[2] << " " << "s'est" << " " << radical << terminaison_auxAvoir_4tmpCompose2[2];
          position(27, 8); cout << personne[2] << " " << "s'était" << " " << radical << terminaison_auxAvoir_4tmpCompose2[2];
          position(55, 8); cout << personne[2] << " " << "se fut" << " " << radical << terminaison_auxAvoir_4tmpCompose2[2];
          position(80, 8); cout << personne[2] << " " << "se sera" << " " << radical << terminaison_auxAvoir_4tmpCompose2[2];
      }
    }else  cout << "le verbe saisi ne ni du deuxieme ni du premier groupe " << endl;

 }


void password() // creer un mot de passe
{
int tes = 0;
heure_date();
    pass :

  string login;
  position(50, 9);   cout<<"|======================CONNEXION=====================|"<<endl;
  position(50, 10) ; cout<<"|  LOGIN    : |                                      |"<<endl;
  position(50, 11) ; cout<<"|=============|======================================|"<<endl;
  position(50, 12) ; cout<<"|  password : |                                      |"<<endl;
  position(50, 13) ; cout<<"|====================================================|"<<endl;

    position(65, 10);
    getline(cin,login); //on place le curseur a la colonne 65 et ligne 10 pour saisir le login
    char passwd[11]; char ch;
   int i = 0;
   for(; i < 10 ;) // on veut que le nombre de caractere du mot de passe soit 10
   {
     position(65 + i, 12);  ch = getch();// on place le curseur a la colonne 65+i et ligne 12
             if(int(ch) == 13) break;// l'orqu'on tape sur entrer on sort dans la boucle
        if(i != 10)
        {
           cout<<"*";// si on tape un caractere on affiche pas le caractere on l'enregistre dans le
           // tableau de caractere de caractere puis on affiche (*) et on increment i pour le prochain caractere
           passwd[i] = ch;
           i++;
        }
   }

   if(i < 10 || i > 10)// si i et superieur ou inferieur a 10
   {
     position(70, 15);  cout<<"Votre Mot de passe doit comporter 8 caractères" << endl;
      system("pause");
      system("cls");
      goto pass;
   }

   if(strcmp(passwd,"groupedara") == 0 && (login == "MIAGEL2UBO")) // on compare le login avec notre login et de meme pour le mot de passe
   {
       position(70, 15); cout<<"vous etes connecter"<<endl;
       system("pause");system("cls");
   } else
    {
        position(70, 15); cout<<"Login ou Mot de passe incorecte"<<endl;
         system("pause");
         system("cls");
         tes++;// a chaque fois qu'on rate le login ou le mot de passe on incremente tes
         if(tes == 3) // si tes atein 3 on arrete le programme
            {
            cout<<"Nombre de teste depassé"<<endl;
            system("pause");
            system("cls");
            exit(1);
            }
         else goto pass;

    }

}



#endif // GESTION_VERBE_H_INCLUDED
