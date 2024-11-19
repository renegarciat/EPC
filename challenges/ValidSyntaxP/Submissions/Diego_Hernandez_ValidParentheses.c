#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/***********************************************************/
/*                 Macro definitions                       */
/***********************************************************/
#define INPUT_BUFFER_SIZE            50u

/*All supported brackets are defined in the following table*/
/*BRACKET(name, 'opening_bracket', 'closing_bracket')*/
#define SUPPORTED_BRACKETS \
BRACKET(bracket_1, '(', ')') \
BRACKET(bracket_2, '[', ']') \
BRACKET(bracket_3, '{', '}') \

/***********************************************************/
/*                 Global variables                        */
/***********************************************************/

/*value given for each bracket*/
enum bracketValue
{
  not_valid = 0,
#define BRACKET(name, opening_bracket, closing_bracket)\
  name,
	SUPPORTED_BRACKETS 
#undef BRACKET
};

/*Used to receive the input provided by the user*/
char inputBuffer[INPUT_BUFFER_SIZE];

/***********************************************************/
/*               Function prototypes                       */
/***********************************************************/

/***********************************************************
Function: isValid
Description: The function takes an input buffer and verifies
             if the number of brackets is correctly opened 
             and closed
Inputs: char* s Buffer with the data to process
Outputs: 
Return: bool result of the operation False in the input 
             was not processed correctly
***********************************************************/
bool isValid(char* s);

/***********************************************************
Function: main
Description: main function executed at program start.
Inputs: void
Outputs: None
Return: int Program exit status
***********************************************************/
int main();

/***********************************************************/
/*               Function definitions                      */
/***********************************************************/

/***********************isValid*****************************/
bool isValid(char* inBuffer) 
{
  int bufferIdx = 0;
  int bracketValue = 0;
  bool retValue = false;
  
  for(bufferIdx = 0; bufferIdx < INPUT_BUFFER_SIZE; bufferIdx++)
  {
    switch(inBuffer[bufferIdx])
    {
#define BRACKET(name, opening_bracket, closing_bracket)\
      case opening_bracket:\
        bracketValue += name;\
        break;\
      case closing_bracket:\
        bracketValue -= name;\
        break;
    	SUPPORTED_BRACKETS 
#undef BRACKET
    }
  }
  
  if(0 == bracketValue)
  {
    retValue = true;
  }
  
  return retValue;
}
/***********************isValid*****************************/

/*************************main******************************/
int main()
{
  scanf("%s", inputBuffer);  
  printf("%s\n", inputBuffer);
  if(isValid(inputBuffer))
  {
    printf("The input is valid\n");
  }
  else
  {
    printf("The input is invalid\n");
  }
	return 0;
}
/*************************main******************************/