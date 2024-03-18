#include <cctype>
#include "removeDigits.hpp"

char * removeDigits(const char * input, char * result)
{
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
