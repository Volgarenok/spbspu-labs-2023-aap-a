#include <cctype>
#include "removeDigits.hpp"

char * vojuck::removeDigits(const char * input, char * result)
{
  if (*input == ' ')
  {
    while (*input == ' ')
    {
      input++;
    }
  }
  while (*input != '\n')
  {
    if (!std::isdigit(*input))
    {
      *result = *input;
      result++;
    }
    input++;
  }
  *result = '\0';
  return result;
}
