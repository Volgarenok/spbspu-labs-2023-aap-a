#include "removeVowels.hpp"
#include "isConsonat.hpp"

char* stepanov::removeVowels(char* string)
{
  char* begin = string;
  char* result = string;
  while (*string != '\0')
  {
    if (stepanov::isConsonat(*string))
    {
      *result = *string;
      ++result;
    }
    ++string;
  }
  *result = '\0';

  return begin;
}
