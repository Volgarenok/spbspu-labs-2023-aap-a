#include "fillNewRepStr.hpp"

void agarkov::fillNewRepStr(const char* source, char* dest)
{
  for (auto i = source; *i != '\0'; i++)
  {
    bool duplicate = false;
    for (auto j = source; j < i; j++)
    {
      if (*j == *i)
      {
        duplicate = true;
        break;
      }
    }
    if (!duplicate)
    {
      bool exist_in_dest = false;
      for (auto j = i + 1; *j != '\0'; j++)
      {
        if (*j == *i)
        {
          exist_in_dest = true;
          break;
        }
      }
      if (exist_in_dest)
      {
        *dest = *i;
        dest++;
      }
    }
  }
  *dest = '\0';
}
