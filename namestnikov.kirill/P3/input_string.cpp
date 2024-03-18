#include "input_string.hpp"

char * getLongerString(char * string, size_t oldSize, size_t newSize)
{
  char * newString = new char[newSize]{};
  for (size_t i = 0; i < oldSize; ++i)
  {
    newString[i] = string[i];
  }
  return newString;
}

char * namestnikov::inputString(std::istream & in, size_t & strIndex)
{
  size_t strSize = 20;
  constexpr size_t defaultSize = 20;
  char * string = new char [defaultSize]{};
  char sym = 0;
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
        char * newString = getLongerString(string, strSize, strSize + 20);
        delete [] string;
        string = newString;
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
