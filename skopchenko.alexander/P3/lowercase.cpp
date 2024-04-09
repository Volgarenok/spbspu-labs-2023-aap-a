#include "lowercase.h"
#include <cstring>
#include <cctype>

char *skopchenko::convertToLowerCase(char *string)
{
  for (size_t i = 0; string[i] != 0; i++)
  {
    if (std::isupper(string[i]) && std::isalpha(string[i]))
    {
      string[i] += 32;
    }
  }
  return string;
}
