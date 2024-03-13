#include "removespaces.hpp"
#include <iostream>

void petuhov::removeSpaces(const char * string, char * output)
{
  if (!string || !output) return;
  size_t index = 0;
  for (size_t i = 0; string[i] != '\0'; ++i)
  {
    if (string[i] != ' ' || (i > 0 && string[i-1] != ' '))
    {
      output[index++] = string[i];
    }
  }
  output[index] = '\0';
}
