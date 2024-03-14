#include "hasDuplicateCharacters.hpp"

int serter::hasDuplicateCharacters(const char* str)
{
  int charCount[256] = {0};
  for (int i = 0; str[i] != '\0'; ++i)
  {
      charCount[str[i]]++;
      if (charCount[str[i]] > 1)
      {
          return charCount[str[i]];
      }
  }
  return 0;
}

