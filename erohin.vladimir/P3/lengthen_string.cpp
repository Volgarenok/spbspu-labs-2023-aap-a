#include "lengthen_string.hpp"

char* erohin::lengthenString(const char* str, size_t size, size_t shift)
{
  char* resized = new char[size + shift + 1]{};
  for (size_t i = 0; i < size; ++i)
  {
    resized[i] = str[i];
  }
  resized[size + shift] = '\0';
  return resized;
}
