#include "deleteDigits.hpp"
#include <cctype>

void baranov::deleteDigits(const char * string, char * result)
{
  size_t i = 0;
  size_t j = 0;
  while (string[i] != '\0')
  {
    if (!std::isdigit(string[i]))
    {
      result[j] = string[i];
      ++j;
    }
    ++i;
  }
}

