/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

/****************************************************************************
*
* 		Macro
*
****************************************************************************/
#define ZERO 0

/****************************************************************************
*
* 		Brackets?
*
****************************************************************************/
int Brackets(char input1, char input2, char InputC, int out)
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
* 		Is valid the input values?
*
****************************************************************************/
int isValid (char *s)
{
    int conti[3] = {0,0 ,0};
    
    for(int i = ZERO; i < strlen(s); i++)
    {
        conti[0] = Brackets('(', ')', s[i], conti[0]);
        conti[1] = Brackets('[', ']', s[i], conti[1]);
        conti[2] = Brackets('{', '}', s[i], conti[2]);
        
        if((ZERO > conti[0]) ||  (ZERO > conti[1]) || (ZERO > conti[2]))
        {
            i = strlen(s);
        }
    }
    if ((ZERO == conti[0]) && (ZERO == conti[1]) && (ZERO == conti[2]))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/****************************************************************************
*
* 		Main function
*
****************************************************************************/
int main()
{
    
    char *c;
    scanf("%ms", &c);
    if(isValid(c))
    {
        printf("es valido \n");
    }
    else{
        printf("es invalido\n");
    }
    return 0;
}
