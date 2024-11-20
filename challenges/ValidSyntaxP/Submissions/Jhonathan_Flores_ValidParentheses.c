#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {

  char openSymbols[100];
  char closeSymbols[100];

  char auxDif = 0;
  char auxCounter = 0;
  char openCounter = 0;
  char closeCounter = 0;

  while('\0' != s[auxCounter] && '\r' != s[auxCounter] && '\n' != s[auxCounter]){
    // Classify received string elements
    if('(' == s[auxCounter] || '{' == s[auxCounter] || '[' == s[auxCounter]){
        openSymbols[openCounter] = s[auxCounter];
        openCounter++;
    }
    else if(')' == s[auxCounter] || ']' == s[auxCounter] || '}' == s[auxCounter]){
        closeSymbols[closeCounter] = s[auxCounter];
        closeCounter++;
    }
    else{
        // Guard 1 to detect invalid element
        return false;
    }
    auxCounter++;
  }

  if(openCounter != closeCounter){
    // Guard 2 to detect an unclosed symbol
    return false;
  }
  else{
    for(auxCounter=0;auxCounter<openCounter;auxCounter++){
        auxDif = closeSymbols[auxCounter] - openSymbols[openCounter-auxCounter-1];
        if(1 != auxDif && 2 != auxDif){
            // Guard 3 to detect a mismatch in open/close symbols
            return false;
        }
        else{
        //   do nothing
        }
    }
    return true;
  }
}