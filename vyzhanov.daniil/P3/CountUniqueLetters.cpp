#include "CountUniqueLetters.hpp"
#include <cctype>

int vyzhanov::countUniqueLetters(const char* string)
{
  int count = 0;
  for (int symbol = 'a'; symbol <= 'z'; symbol++)
  {
    const char* secString = string;
    while (*secString)
    {
      if (*secString == symbol)
      {
        count++;
        break;
      }
      secString++;
    }
  }
  return count;
}
