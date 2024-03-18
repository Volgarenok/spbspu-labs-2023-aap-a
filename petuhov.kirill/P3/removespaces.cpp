#include "removespaces.hpp"
#include <cstddef>

void petuhov::removeSpaces(const char * string, char * output)
{
  if (!string || !output)
  {
    return;
  }
  const char * start = string;
  while (*string != '\0')
  {
    if (*string != ' ' || (string != start && *(string - 1) != ' '))
    {
      *output++ = *string;
    }
    string++;
  }
  *output = '\0';
}
