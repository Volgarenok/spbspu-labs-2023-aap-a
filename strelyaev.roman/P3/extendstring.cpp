#include "extendstring.h"

int strelyaev::checkRepDgt(const char * const string)
{
  for (size_t i = 0; string[i] != '\0'; i++)
  {
    if (std::isdigit(string[i]))
    {
      for (size_t j = 0; string[j] != '\0'; j++)
      {
        if ((string[i] == string[j]) && (i != j))
        {
          return 1;
        }
      }
    }
  }
  return 0;
}
