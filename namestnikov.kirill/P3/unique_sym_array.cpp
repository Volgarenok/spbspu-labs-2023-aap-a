#include "unique_sym_array.hpp"
#include <algorithm>

void namestnikov::fillUniqueSymArray(const char * str1, const char * str2, char * result, size_t & resultIndex)
{
  const char * temp = str1;
  while (*temp != '\0')
  {
    if (!(isSymbolInString(str2, *temp)) && !(isSymbolInString(result, *temp)))
    {
      result[resultIndex] = *temp;
      ++resultIndex;
    }
    ++temp;
  }
}

bool namestnikov::isSymbolInString(const char * string, char sym)
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

char * namestnikov::getUniqueSymArray(const char * str1, const char * str2, size_t firstSize, size_t secondSize)
{
  size_t resultIndex = 0;
  size_t defaultSize = std::max(firstSize, secondSize);
  char * result = new char[defaultSize]{};
  fillUniqueSymArray(str1, str2, result, resultIndex);
  fillUniqueSymArray(str2, str1, result, resultIndex);
  result[resultIndex] = '\0';
  std::sort(result, result + resultIndex);
  return result;
}
