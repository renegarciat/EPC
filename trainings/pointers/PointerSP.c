/**************************************************************************************************
APTIV
11/06/24
-Pointers
EMBEDDED PROGRAMMING COMUNITY
***************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Ejemplos de variables apuntadores
    int numero1=15;
    int  *puntero_int=&numero1;

    float numero2=12.34;
    float *puntero_float;

    puntero_float=&numero2;

    printf("numero 1: %d\n", numero1);
    printf("Direccion de numero 1: %p\n", &numero1);

    printf("numero 2: %.2f\n", numero2);
    printf("Direccion de numero 2: %p", &numero2);

    //Editamos valores de numero1 y numero2 utilizando  el puntero
    *puntero_int=11;
    *puntero_float=5.14;

    //Despues de modificar el dato en la pos de memoria
    printf("\nnumero 1: %d\n", numero1);
    printf("numero 2: %.2f\n", numero2);

    //Indireccionando el apuntador
    printf("\nIndireccionando");
    printf("\nnumero 1: %d\n", *puntero_int);
    printf("numero 2: %.2f\n", *puntero_float);

    return 0;
}