#include "consecutiveDup.hpp"

int spiridonov::hasConsecutiveDuplicates(const char * str)
{
  if (str == nullptr || *str == '\n')
  {
    return 0;
  }

  const char* current = str;

  while (*current)
  {
    if (*(current + 1))
    {
      if (*current == *(current + 1))
      {
        return 1;
      }
      current++;
    }
    else
    {
      break;
    }
  }
  return 0;
}
