#include <iostream>
#include <string>
#include "copyNum.hpp"

char* sivkov::copyNum(char* string1, char* string2)
{
  size_t k1 = 0;
  size_t k2 = 0;
  size_t k3 = 0;
  for (size_t i = 0; string1[i] != '\0'; i++)
  {
    k1++;
  }
  for (size_t i = 0; string2[i] != '\0'; i++)
  {
    k2++;
  }

  char* finalString = new char[k1 + k2 + 1];
  if (!finalString)
  {
    string1 = nullptr;
    return string1;
  }
  for (size_t j = 0; j < k1; j++)
  {
    finalString[k3++] = string1[j];
  }
  for (size_t j = 0; j < k2; j++)
  {
    if (std::isdigit(string2[j]))
    {
      finalString[k3++] = string2[j];
    }
  }
  finalString[k3] = '\0';
  return finalString;
}
