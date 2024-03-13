#include "substractstring.hpp"

void petuhov::substractString(char * firstString, const char * secondString)
{
  if (!firstString || !secondString)
  {
    return;
  }
  size_t index = 0;

  for (int i = 0; firstString[i] != '\0'; ++i)
  {
    bool charFound = 0;

    for (int j = 0; secondString[j] != '\0'; ++j)
    {
      if (firstString[i] == secondString[j])
      {
        charFound = 1;
        break;
      }
    }

    if (!charFound)
    {
      firstString[index++] = firstString[i];
    }
  }
  firstString[index] = '\0';
}
