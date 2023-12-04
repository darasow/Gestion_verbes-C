#include "gestion_verbe.h"
int main()
{
    SetConsoleTitle("LOGICIEL DE CONJUGUAISON");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);
    back_graound(BACKUP_SECURITY_DATA);
           presentation();
        fiche_de_rencontre();
           password();
       ver: gestion_verbe();
   int resul = MessageBoxA(NULL,"Voulez vous quittez ?","Confirmation",MB_ICONQUESTION|MB_OKCANCEL);
   if(resul != MB_OKCANCEL)
    {  system("cls");
     goto ver;
    }

       return 0;
}
