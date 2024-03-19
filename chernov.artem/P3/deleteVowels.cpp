#include "deleteVowels.hpp"
#include <cstddef>

char* chernov::removeVowels(char* input, char* stringWithVowelsRemoved, size_t sizeOfInput)
{
  size_t j = 0;
  char vowels[6] = { 'a', 'y', 'e', 'u', 'i', 'o' };
  for (size_t i = 0; (input[i] != '\0') && (i < sizeOfInput); i++)
  {
    bool flag = false;
    for (size_t k = 0; k < 6; k++)
    {
      if (input[i] == vowels[k])
      {
        flag = true;
        break;
      }
    }
    if (!flag)
    {
      stringWithVowelsRemoved[j] = input[i];
      j++;
    }
  }
  stringWithVowelsRemoved[j] = '\0';
  return stringWithVowelsRemoved;
}
