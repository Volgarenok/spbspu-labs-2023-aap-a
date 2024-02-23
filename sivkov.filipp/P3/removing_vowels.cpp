#include "removing_vowels.hpp"
#include <cstddef>

void sivkov::removing_vowels(char* string)
{
  const char* vowels = "AEIOUaeiou";

  char* oldPtr = string;
  char* newPtr = string;

  while (*oldPtr != '\0')
  {
    bool isVowel = false;

    for (size_t i = 0; i < 10; ++i)
    {
      if (*oldPtr == vowels[i])
      {
        isVowel = true;
        break;
      }
    }
    if (!isVowel)
    {
      *newPtr = *oldPtr;
      ++newPtr;
    }
    ++oldPtr;
  }
  *newPtr = '\0';
}
