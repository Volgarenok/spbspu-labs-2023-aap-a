#include "has_rep_digit.hpp"
#include <cstddef>
#include <cctype>

int ishmuratov::hasRepDigit(const char * str)
{
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    for (size_t j = 0; str[j] != '\0'; j++)
    {
      if ((std::isdigit(str[i])) && (i != j) && (str[i] == str[j]))
      {
        return 1;
      }
    }
  }
  return 0;
}
