#include "hasDuplicateCharacters.hpp"
#include <stdexcept>

int serter::hasDuplicateCharacters(const char* str)
{
  if (str == nullptr)
  {
    throw std::invalid_argument("Null pointer passed to countDuplicateCharacters");
  }

  bool characters[256] = {false};

  while (*str != '\0')
  {
    if (characters[*str])
    {
      return 1;
    }
    characters[*str] = true;
    ++str;
  }

  return 0;
}

