#include "stringOperations.h"

void makeCopy(char *dest, const char *src)
{
  for (; *src != '\0'; ++src, ++dest)
  {
    *dest = *src;
  }
}

char *zakozhurnikova::getExtendedString(char *string, char *str)
{
  makeCopy(string, str);
  delete[] str;
  return string;
}

