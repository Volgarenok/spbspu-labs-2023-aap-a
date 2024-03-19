#include "stringinput.h"
#include <stdexcept>

char *skopchenko::stringInput(std::istream &input)
{
  char currChar = 0;
  size_t size = 14;
  size_t i = 0;
  char *dynamicString = new char[size]();

  input >> std::noskipws;

  while (input >> currChar)
  {
    if (!input)
    {
      delete[] dynamicString;
      throw std::logic_error("Couldn't input string\n");
    }

    if (currChar == '\n')
    {
      dynamicString[i] = '\0';
      break;
    }

    if (i == size - 1)
    {
      size *= 2;
      try
      {
        char *newString = new char[size]();
        std::copy(dynamicString, dynamicString + i, newString);
        delete[] dynamicString;
        dynamicString = newString;
      }
      catch (const std::bad_alloc &e)
      {
        delete[] dynamicString;
        input >> std::skipws;
        throw;
      }
    }
    dynamicString[i] = currChar;
    i++;
  }

  input >> std::skipws;
  return dynamicString;

}
