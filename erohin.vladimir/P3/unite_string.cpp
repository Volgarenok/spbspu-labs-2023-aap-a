#include "unite_string.hpp"
#include <cstddef>
#include <stdexcept>

char * erohin::uniteString(char * result, const char * str1, const char * str2)
{
  size_t i = 0;
  size_t j = 0;
  while (str1[i] != '\0' || str2[j] != '\0')
  {
    if (str1[i] != '\0')
    {
      result[i + j] = str1[i];
      ++i;
    }
    if (str2[j] != '\0')
    {
      result[i + j] = str2[j];
      ++j;
    }
  }
  result[i + j] = '\0';
  return result;
}
