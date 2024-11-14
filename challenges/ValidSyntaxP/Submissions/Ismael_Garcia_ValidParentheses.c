bool isValid(char* s) {
  
  int  index            = 0;
  char currentBraceType = 0;
  bool validString      = false;
  int  top              = 0;
  char delta            = 1;
  char stack[100];
  
  while(s[index] != '\0')
  {
    if((s[index] == ')') || (s[index] == ']') || (s[index] == '}'))
    {
        if(s[index] == ')')
        {
            delta = 1;
        }
        else
        {
            delta = 2;
        }
      if(s[index] != currentBraceType+delta)
      {
        validString = false;
        break;
      }
      else if (s[index + 1] == '\0')
      {
        validString = true;
        break;
      }
      else
      {
        top-=2;
        currentBraceType = stack[top];
      }
    }
    else
    {
      currentBraceType = s[index];
      stack[top] = currentBraceType;
      top++;
    }
    
    index++;
  }
  
  return validString;
}
