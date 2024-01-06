#include "deleteLatinLetters.hpp"
#include <cctype>

char* novokhatskiy::deleteLatinLetters(const char* in, char* out)
{
  char* result = out;
  do
  {
    if (!std::isalpha(*in))
    {
      *out++ = *in;
    }
  }
  while (*in++);
  return result;
}
