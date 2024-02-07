#include "removeSpaces.h"

void zakozhurnikova::removeSpaces(char *dest, const char *src)
{
  ++src;
  for (; *src != '\0'; ++src)
  {
    if (*(src - 1) != ' ')
    {
      *dest = *(src - 1);
      ++dest;
    }
    if (*src == ' ' && *(src - 1) != ' ')
    {
      *dest = *src;
      ++dest;
    }
  }

  if (*(dest - 1) == ' ')
  {
    *(dest - 1) = '\0';
  }
}
