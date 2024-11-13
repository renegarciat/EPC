/**********************************************************************************************
APTIV
11/09/24
-Pointers as arguments to functions
EMBEDDED PROGRAMMING COMUNITY
***********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int alta;
    int baja;
}TEMPERATURA;

void RegistroTemp(TEMPERATURA *tmp, int *actual);


int main()
{
    TEMPERATURA tmp;
    int actual;
    int limI=100;
    int limS=200;

    srand(time(NULL)); //Semilla

    tmp.baja=rand()%limI;
    tmp.alta=limI + rand() % (limS-limI+1);

   

    printf("\nTemperatura al iniciar. \n");
    printf("Temperatura baja: %d\n", tmp.baja);
    printf("Temperatura alta: %d\n", tmp.alta);

    actual=rand()%limS;
    RegistroTemp(&tmp, &actual);
    printf("\nMedimos temperatura: %d\n", actual);

    printf("\nTemperatura al finalizar.\n ");
    if(tmp.baja!=tmp.alta)
    {
      printf("Temperatura baja: %i\n", tmp.baja);
      printf("Temperatura alta: %i\n", tmp.alta);
    }
    else
    printf("La temperatura no cambio.");
    

    return 0;
}

void RegistroTemp(TEMPERATURA *tmp, int *actual)
{
    if(*actual > tmp->alta)
        tmp->alta=*actual;
    if(*actual < tmp->baja)
        tmp->baja=*actual;
        
}