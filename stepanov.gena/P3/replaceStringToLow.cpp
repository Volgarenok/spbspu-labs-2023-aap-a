#include "replaceStringToLow.hpp"
#include <cctype>
#include <cstddef>

char* stepanov::replaceStringToLow(char* string)
{
  for (size_t i = 0; string[i] != '\0'; ++i)
  {
    if (std::isalpha(string[i]) && std::isupper(string[i]))
    {
      string[i] = std::tolower(string[i]);
    }
  }
  return string;
}
