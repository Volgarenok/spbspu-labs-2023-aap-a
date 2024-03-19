#include <cctype>
#include "removeDigits.hpp"

char * vojuck::removeDigits(const char * input, char * result)
{
  int i = 0, j = 0;
  if (input[i] == ' ')
  {
    while (input[i] == ' ')
    {
      i++;
    }
  }
  while (input[i] != '\n')
  {
    if (!std::isdigit(input[i]))
    {
      result[j] = input[i];
      j++;
    }
    i++;
  }
  result[j] = '\0';
  return result;
}
