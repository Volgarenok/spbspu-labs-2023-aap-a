#include "hasDuplicateCharacters.hpp"
#include <cstddef>

int serter::hasDuplicateCharacters(const char* str, size_t sizeOfString)
{
  int charCount[256] = {0};
  for (size_t i = 0; i < sizeOfString; ++i)
  {
    char currentChar = str[i];
    charCount[currentChar]++;
    if (charCount[currentChar] > 1)
    {
      return 1;
    }
  }
  return 0;
}

