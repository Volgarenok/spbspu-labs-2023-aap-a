#include "isConsonat.hpp"

bool stepanov::isConsonat(char symbol)
{
  const char* listVowels = "AEIOUaeiou";
  bool flag = true;
  while (*listVowels != '\0')
  {
    if (symbol == *listVowels)
    {
      flag = false;
      break;
    }
    ++listVowels;
  }
  return flag;
}
