#include "check_matches.hpp"

int nikitov::checkMatches(const char* firstArray, const char* secondArray, size_t firstSize, size_t secondSize)
{
  for (size_t i = 0; i != firstSize; ++i)
  {
    char symb1 = firstArray[i];
    if (symb1 == '\0')
    {
      break;
    }
    for (size_t j = 0; j != secondSize; ++j)
    {
      char symb2 = secondArray[j];
      if (symb2 == '\0')
      {
        break;
      }
      else if (symb1 == symb2)
      {
        return 1;
      }
    }
  }

  return 0;
}
