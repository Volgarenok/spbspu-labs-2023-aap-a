#include "duplicateNumbers.h"
#include <cstddef>
#include <cctype>

size_t shabalin::duplicateNumbers(const char *const str)
{
  if (str == nullptr || *str == '\0')
  {
    return 0;
  }

  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    if (std::isdigit(str[i]))
    {
      for (size_t j = 0; str[j] != '\0'; ++j)
      {
        if (((str[i] == str[j])) && (i != j))
        {
          return 1;
        }
      }
    }
  }
  return 0;
}
