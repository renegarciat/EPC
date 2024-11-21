#include <stdbool.h>
#include <string.h>

// No fixed arrays usage

bool isValid(char* s) {
  char auxDif = 0;
  char auxPairs = 0;
  char auxModule = 0;
  char auxCounter = 0;
  char totalSymbols = 0;

  while('\0' != s[totalSymbols] && '\r' != s[totalSymbols] && '\n' != s[totalSymbols]){
    // Validate received string elements
    if('(' == s[totalSymbols] || '{' == s[totalSymbols] || '[' == s[totalSymbols] || ')' == s[totalSymbols] || ']' == s[totalSymbols] || '}' == s[totalSymbols]){
        totalSymbols++;
    }
    else{
        // Guard 1 to detect invalid element
        return false;
    }
  }

  auxPairs = totalSymbols/2;
  auxModule = totalSymbols%2;
  if(0 != auxModule){
    // Guard 2 to detect an unclosed symbol
    return false;
  }
  else{
    for(auxCounter=0;auxCounter<auxPairs;auxCounter++){
        auxDif = s[totalSymbols-auxCounter-1] - s[auxCounter];
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