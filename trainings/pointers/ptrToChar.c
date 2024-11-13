/**********************************************************************************************
13/09/21
Taller de punteros -S2
-Apuntadores a cadenas
***********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Declaramos la cadena
    char alfabeto[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *ptrAlfabeto;
    ptrAlfabeto=&alfabeto[0]; //alfabeto;
    unsigned int t;

    //puts(alfabeto);
    //ptrAlfabeto=ptrAlfabeto+2; //Imprimimos la letra  C
   // printf("\n%c \n", *ptrAlfabeto);

    for(t=0; t<strlen(alfabeto); t++) //Imprimimos la cadena caracter a caracter
    {
        printf("%c", *ptrAlfabeto);
        ptrAlfabeto=ptrAlfabeto+1;
    }
    printf("\n\n\n");

    for(t=0; t<=strlen(alfabeto); t++) //Imprimimos de reversa
    {
        printf("%c", *ptrAlfabeto);
        ptrAlfabeto=ptrAlfabeto-1;
    }

     printf("\n\n\n");

    return 0;
}
