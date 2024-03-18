#include "makeLowerCaseString.h"
#include <cstddef>
#include <cctype>

void shabalin::makeLowerCaseString(char* str)
{
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    if (std::isupper(str[i]))
    {
      str[i] = std::tolower(str[i]);
    }
  }
}
