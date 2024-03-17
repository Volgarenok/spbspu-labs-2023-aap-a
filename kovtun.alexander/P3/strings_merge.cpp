#include "strings_merge.h"

char * kovtun::mergeStrings(char * destination, const char * first, const char * second)
{
  char * destinationBegin = destination;
  while (*first != '\0' || *second != '\0')
  {
    if (*first != '\0')
    {
      *destination = *first;
      first++;
      destination++;
    }

    if (*second != '\0')
    {
      *destination = *second;
      second++;
      destination++;
    }
  }
  *destination = '\0';

  return destinationBegin;
}

