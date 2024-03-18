#include "unique_sym_array.hpp"

bool isSymbolInString(const char * string, char sym)
{
  while (*string != '\0')
  {
    if (*string == sym)
    {
      return true;
    }
    ++string;
  }
  return false;
}

void namestnikov::getUniqueSymArray(const char * str1, const char * str2, char * result)
{
  size_t i = 0;
  size_t j = 0;
  while (str1[i] != '\0')
  {
    if (!(isSymbolInString(str2, str1[i])) && !(isSymbolInString(result, str1[i])))
    {
      result[j] = str1[i];
      ++j;
    }
    ++i;
  }
  i = 0;
  while (str2[i] != '\0')
  {
    if (!(isSymbolInString(str1, str2[i])) && !(isSymbolInString(result, str2[i])))
    {
      result[j] = str2[i];
      ++j;
    }
    ++i;
  }
}
