#include "removeSpaces.h"
#include <cctype>

void zakozhurnikova::removeSpaces(char *dest, const char *src)
{
  if (!dest || !src)
  {
    return;
  }
  ++src;
  for (; *(src - 1) != '\0'; ++src)
  {
    if (!std::isspace(*(src - 1)))
    {
      *dest = *(src - 1);
      ++dest;
    }
    if (std::isspace(*src) && !std::isspace(*(src - 1)))
    {
      *dest = *src;
      ++dest;
    }
  }

  if (std::isspace(*(dest - 1)))
  {
    *(dest - 1) = '\0';
  }
}
