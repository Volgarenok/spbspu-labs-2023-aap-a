#include <cctype>
#include "removeDigits.hpp"

char * vojuck::removeDigits(const char * input, char * result)
{
  while (*input != '\0')
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
