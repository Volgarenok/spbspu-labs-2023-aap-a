#include <cctype>
#include "removeLetters.hpp"

char * vojuck::removeLetters(const char * input, char * result)
{
  while (*input != '\n')
  {
    if (!std::isalpha(*input))
    {
      *result = *input;
      result++;
    }
    input++;
  }
  *result = '\0';
  return result;
}
