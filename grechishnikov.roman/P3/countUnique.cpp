#include "countUnique.hpp"
#include <cctype>

size_t grechishnikov::countUnique(const char* str)
{
  size_t result = 0;
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    if (std::isalpha(str[i]))
    {
      char del = std::tolower(str[i]);
      int check = 1;
      for (size_t g = 0; g < i; ++g)
      {
        if (del == std::tolower(str[g]))
        {
          check = 0;
          break;
        }
      }
      if (check == 1)
      {
        result++;
      }
    }
  }
  return result;
}
