#include "has_rep_symbol.hpp"
#include <cstddef>

int ishmuratov::hasRep(const char * string)
{
  for (size_t i = 0; string[i] != '\0'; i++)
  {
    for (size_t j = 0; string[j] != '\0'; j++)
    {
      if ((i != j) && (string[i] == string[j]))
      {
        return 1;
      }
    }
  }
  return 0;
}
