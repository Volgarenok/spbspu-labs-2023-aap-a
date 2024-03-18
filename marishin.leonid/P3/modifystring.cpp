#include "modifystring.hpp"

char* marishin::modifyString(char* string, char firstSymbol, char secondSymbol)
{
  char* current = string;
  while (*current != '\0')
  {
    if (*current == firstSymbol)
    {
      *current = secondSymbol;
    }
    ++current;
  }
  return string;
}
