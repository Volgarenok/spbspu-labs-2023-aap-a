#include "removeDuplicate.hpp"
#include <iostream>
#include <cstring>

char* removeDuplicate(const char* str1, const char* str2)
{
  char result[100];
  strcpy(result, str1);

  int len1 = strlen(result);
  int len2 = strlen(str2);

  for (int i = 0; i < len2; i++)
  {
    char* pos = nullptr;
    while ((pos = strchr(result, str2[i])) != nullptr)
    {
      memmove(pos, pos + 1, strlen(pos));
      len1--;
    }
  }
  result[len1] = '\0';
  return result;
}
