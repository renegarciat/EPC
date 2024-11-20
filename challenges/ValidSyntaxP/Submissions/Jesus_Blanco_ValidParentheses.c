/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

/****************************************************************************
*
* 				Macro
*
****************************************************************************/
#define ZERO 0

/****************************************************************************
*
* 				Is valid the input values?
*
****************************************************************************/
int isValid (char input1, char input2, char InputC, int out)
{
    if(input1 == InputC)
    {
        out += 1;
    }
    else if (input2 == InputC)
    {
        out -= 1;
    }
    else{
        //do nothing;
    }
    return out;
}

/****************************************************************************
*
* 					Main function
*
****************************************************************************/
int main()
{
    int conti[3] = {0,0 ,0};
    char *c;
    scanf("%ms", &c);
    for(int i = ZERO; i < strlen(c); i++)
    {
        conti[0] = isValid('(', ')', c[i], conti[0]);
        conti[1] = isValid('[', ']', c[i], conti[1]);
        conti[2] = isValid('{', '}', c[i], conti[2]);
        
        if((ZERO > conti[0]) ||  (ZERO > conti[1]) || (ZERO > conti[2]))
        {
            i = strlen(c);
        }
    }
    if((ZERO == conti[0]) && (ZERO == conti[1]) && (ZERO == conti[2]))
    {
        printf("es valido \n");
    }
    else{
        printf("es invalido\n");
    }
    return 0;
}
