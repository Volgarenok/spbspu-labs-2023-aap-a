#include "stringOperations.h"

void zakozhurnikova::makeCopy(char *dest, const char *src)
{
  for (; *src != '\0'; ++src, ++dest)
  {
    *dest = *src;
  }
}

void zakozhurnikova::swapStrings(char *&dest, char *&src)
{
  char *temp = dest;
  dest = src;
  src = temp;
}

