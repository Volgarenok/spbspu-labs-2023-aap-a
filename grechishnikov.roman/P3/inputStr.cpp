#include "inputStr.hpp"

char* grechishnikov::inputStr(std::istream& in, size_t& size)
{
  size_t len = 10;
  char * curStr = nullptr;
  try
  {
    curStr = new char[len];
  }
  catch (const std::bad_alloc &e)
  {
    throw std::logic_error("Cannot allocate memory");
  }

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
        curStr = reallocate(curStr, len, len + 10);
      }
      catch (const std::bad_alloc &e)
      {
        throw std::logic_error("Cannot allocate mamory");
      }
      len += 10;
    }
  }
  if (curPos == 0)
  {
    delete[] curStr;
    throw std::logic_error("String is empty");
  }
  in >> std::skipws;
  size = curPos;
  return curStr;
}

char* grechishnikov::reallocate(char* str, size_t lenF, size_t lenS)
{
  char* newStr = new char [lenS];
  for (size_t i = 0; i < lenS; ++i)
  {
    newStr[i] = 0;
  }
  size_t min = (lenF < lenS) ? lenF : lenS;
  for (size_t i = 0; i < min; ++i)
  {
    newStr[i] = str[i];
  }
  delete[] str;
  return newStr;
 }
