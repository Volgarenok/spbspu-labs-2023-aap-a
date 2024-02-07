#include "inputString.hpp"
#include <iomanip>
#include <iostream>
#include <stdexcept>

char * isaychev::inputString(std::istream & input, size_t & length1, size_t & capacity)
{
  char * str = nullptr;
  try
  {
    str = new char[capacity]{};
    char currChar = 0;
    input >> std::noskipws;
    while ((input >> currChar) && (length1 < capacity))
    {
      if (length1 == capacity - 1)
      {
        capacity += 10;
        char * biggerStr = new char[capacity]{};
        copyString(str, biggerStr);
        delete [] str;
        str = biggerStr;
      }
      str[length1] = currChar;
      if (currChar == '\n')
      {
        str[length1] = '\0';
        break;
      }
      length1++;
    }
    if (length1 == 0)
    {
      delete [] str;
      throw std::logic_error("Not enough characters in string");
    }
  }
  catch (const std::bad_alloc &)
  {
    delete [] str;
    throw;
  }
  input >> std::skipws;
  return str;
}

void isaychev::copyString(const char * str1, char * str2)
{
  for (size_t j = 0; str1[j] != '\0'; ++j)
  {
    str2[j] = str1[j];
  }
}
