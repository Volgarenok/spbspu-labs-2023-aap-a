#include "hasDuplicateCharacters.hpp"
#include <cstddef>

int serter::hasDuplicateCharacters(const char* str, size_t sizeOfString)
{
  for (size_t i = 0; i < sizeOfString - 1; ++i)
  {
    for (size_t j = i + 1; j < sizeOfString; ++j)
    {
      if (str[i] == str[j])
      {
        return 1;
      }
    }
  }
  return 0;
}

