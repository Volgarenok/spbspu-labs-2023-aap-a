#include "addLat.hpp"
#include <cctype>
#include <utility>

void isaychev::fillInUniqueChars(const char * str_base, char * str_final, size_t & counter)
{
  size_t i = 0, j = 0, checkForSameChar = 0;
  while (str_base[j] != '\0')
  {
    if (std::isalpha(str_base[j]))
    {
      while (str_final[i] != '\0')
      {
        if (str_final[i] == std::tolower(str_base[j]))
        {
          checkForSameChar++;
        }
        i++;
      }
      i = 0;
      if (checkForSameChar == 0)
      {
        str_final[counter++] = std::tolower(str_base[j]);
      }
      checkForSameChar = 0;
    }
    j++;
  }
}

void isaychev::addLat(const char * str1, const char * str2, char * str3)
{
  size_t num = 0;
  size_t & linkToCounter = num;
  fillInUniqueChars(str1, str3, linkToCounter);
  fillInUniqueChars(str2, str3, linkToCounter);

  for (size_t i = 0; i < num - 1; ++i)
  {
    for (size_t k = 0; k < num - i - 1; ++k)
    {
      if (str3[k] > str3[k + 1])
      {
        std::swap(str3[k], str3[k + 1]);
      }
    }
  }
  str3[num] = '\0';
}
