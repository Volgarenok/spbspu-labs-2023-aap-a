#include "stringConvert.hpp"
#include <cstddef>
#include <cctype>

void rebdev::convertString(char const * const firstString, char const * const secondString, char * endString)
{
  size_t i = 0;
  while (firstString[i] != '\0')
  {
    endString[i] = firstString[i];
    i += 1;
  }
  size_t j = 0;
  while (secondString[j] != '\0')
  {
    if (std::isdigit(secondString[j]))
    {
      endString[i] = secondString[j];
      i += 1;
    }
    j += 1;
  }
}
