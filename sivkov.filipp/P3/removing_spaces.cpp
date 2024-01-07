#include "removing_spaces.hpp"
#include <iostream>
char* sivkov::deleteSpace(char* string)
{
  size_t k = 0;
  for (size_t i = 0; string[i] != '\0'; i++)
  {
    k++;
  }
  char* arrayWithOutSpace = new char[k+1];
  size_t isSpace = 0;
  size_t indexArr = 0;
  for (size_t j = 0; j < k; j++)
  {
    if (std::isspace(string[j]))
    {
      if (isSpace == 0)
      {
        arrayWithOutSpace[indexArr++] = ' ';
        isSpace = 1;
      }
    }
    else
    {
      arrayWithOutSpace[indexArr++] = string[j];
      isSpace = 0;
    }
  }
  if (indexArr > 0 && arrayWithOutSpace[0] == ' ')
  {
    for (size_t j = 0; j < indexArr - 1; j++)
    {
      arrayWithOutSpace[j] = arrayWithOutSpace[j + 1];
    }
    indexArr--;
  }
  arrayWithOutSpace[indexArr] = '\0';
  return arrayWithOutSpace;
}
