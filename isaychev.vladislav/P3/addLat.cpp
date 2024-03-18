#include "addLat.hpp"
#include <cctype>
#include <utility>
#include <cstddef>

void fillInUniqueChars(const char * str1, char * str2, size_t & counter)
{
  size_t i = 0, j = 0, checkForSameChar = 0;
  while (str1[j] != '\0')
  {
    if (std::isalpha(str1[j]))
    {
      while (str2[i] != '\0')
      {
        if (str2[i] == std::tolower(str1[j]))
        {
          checkForSameChar++;
        }
        i++;
      }
      i = 0;
      if (checkForSameChar == 0)
      {
        str2[counter++] = std::tolower(str1[j]);
      }
      checkForSameChar = 0;
    }
    j++;
  }
}

void sortCharsAZ(char * str)
{
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    for (size_t k = 0; str[k + 1] != '\0'; ++k)
    {
      if (str[k] > str[k + 1])
      {
        std::swap(str[k], str[k + 1]);
      }
    }
  }
}

void isaychev::addLat(const char * str1, const char * str2, char * str3)
{
  size_t num = 0;
  fillInUniqueChars(str1, str3, num);
  fillInUniqueChars(str2, str3, num);
  sortCharsAZ(str3);
  str3[num] = '\0';
}
