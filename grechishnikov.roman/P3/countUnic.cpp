#include "countUnic.hpp"

size_t grechishnikov::countUnic(char* str, size_t len)
{
  size_t rez = 0;
  char unicLett[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  size_t lenStr = 52;
  for (size_t i = 0; i < len; ++i)
  {
    for (size_t g = 0; g < lenStr; ++g)
    {
      if (str[i] == unicLett[g])
      {
        for (size_t j = g; j < lenStr - 1; ++j)
        {
          unicLett[j] = unicLett[j + 1];
        }
        lenStr--;
        rez++;
      }
    }
  }
  return rez;
}
