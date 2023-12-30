#include "input_string.hpp"


char * namestnikov::getLongerString(char * string, size_t oldSize, size_t newSize)
{
  char * newString = new char[newSize];
  for (size_t i = 0; i < newSize; ++i)
  {
    if (i < oldSize)
    {
      newString[i] = string[i];
    }
    else
    {
      newString[i] = '0';
    }
  }
  delete [] string;
  return newString;
}

char * namestnikov::inputString(std::istream & in, size_t & strIndex)
{
  size_t strSize = 0;
  constexpr size_t defaultSize = 20;
  strSize = defaultSize;
  char * string = new char [defaultSize]{};
  string[0] = '\0';
  char sym = '0';
  in >> std::noskipws;
  while (in >> sym)
  {
    if (sym == '\n')
    {
      break;
    }
    else
    {
      string[strIndex] = sym;
    }
    if (strIndex + 1 == strSize)
    {
      try
      {
        string = getLongerString(string, strSize, strSize + 20);
        strSize += 20;
      }
      catch (...)
      {
        delete [] string;
        throw;
      }
    }
    ++strIndex;
    string[strIndex] = '\0';
  }
  in >> std::skipws;
  return string;
}
