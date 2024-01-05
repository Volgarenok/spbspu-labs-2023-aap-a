#include "extractChars.hpp"

void isaychev::extractChars(const char * str_base, const char * str_sec, char * wk_str)
{
  size_t i = 0, j = 0;
  while (str_base[i] != '\0')
  {
    size_t check = checkForSameElem(str_base, str_sec, i);
    if (check == 0)
    {
      wk_str[j] = str_base[i];
      j++;
    }
    i++;
  }
}

size_t isaychev::checkForSameElem(const char * str1, const char * str2, size_t arrayIndex)
{
  size_t check = 0, k = 0;
  while (str2[k] != '\0')
  {
    if (str1[arrayIndex] == str2[k])
    {
      check++;
    }
    k++;
  }
  return check;
}
