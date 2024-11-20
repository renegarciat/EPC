#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
  unsigned int charCounter = 0;
  
  while('\0' != s[charCounter]){
    if('(' != s[charCounter] && '{' != s[charCounter] && '[' != s[charCounter]){
        return false;
    }
    else{
      if(')' != s[charCounter+1] && ']' != s[charCounter+1] && '}' != s[charCounter+1]){
        return false;
      }
      else{
        charCounter += 2;
      }
    }
  }
  return true;
}