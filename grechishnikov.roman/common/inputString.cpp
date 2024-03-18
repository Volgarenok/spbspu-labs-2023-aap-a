#include "inputString.hpp"
#include <stdexcept>
#include <algorithm>

char* reallocate(const char* str, size_t lenF, size_t lenS);

const char* grechishnikov::inputString(std::istream& in)
{
  size_t len = 10;
  char* curStr = new char[len];
  char chInput = '0';
  size_t curPos = 0;

  in >> std::noskipws;
  while (in >> chInput)
  {
    if (chInput == '\n')
    {
      curStr[curPos] = '\0';
      break;
    }
    curStr[curPos] = chInput;
    curPos++;
    if (curPos % len == 0)
    {
      try
      {
        char* tempStr = reallocate(curStr, len, len + 10);
        delete[] curStr;
        curStr = tempStr;
      }
      catch (const std::bad_alloc &e)
      {
        delete[] curStr;
        throw;
      }
      len += 10;
    }
  }
  if (curPos == 0)
  {
    delete[] curStr;
    return nullptr;
  }
  in >> std::skipws;
  return curStr;
}

char* reallocate(const char* str, size_t lenF, size_t lenS)
{
  char* newStr = new char[lenS];
  for (size_t i = 0; i < lenS; ++i)
  {
    newStr[i] = 0;
  }
  size_t min = std::min(lenF, lenS);
  for (size_t i = 0; i < min; ++i)
  {
    newStr[i] = str[i];
  }
  return newStr;
}
