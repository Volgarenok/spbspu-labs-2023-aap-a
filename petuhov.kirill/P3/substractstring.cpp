#include "substractstring.hpp"

void petuhov::substractString(char * firstString, const char * secondString)
{
  if (!firstString || !secondString)
  {
    return;
  }

  char *pFirst = firstString;
  const char *pSecond = nullptr;
  bool charFound = false;

  while (*pFirst)
  {
    charFound = false;
    pSecond = secondString;

    while (*pSecond)
    {
      if (*pFirst == *pSecond)
      {
        charFound = true;
        break;
      }
      ++pSecond;
    }

    if (!charFound)
    {
      *firstString++ = *pFirst;
    }
    ++pFirst;
  }
  *firstString = '\0';
}
