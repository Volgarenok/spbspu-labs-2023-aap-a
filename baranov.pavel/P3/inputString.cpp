#include "inputString.hpp"

char * baranov::expandString(const char * string, const size_t newSize)
{
  char * result = new char[newSize]{};
  size_t i = 0;
  while (string[i] != '\0')
  {
    result[i] = string[i];
    ++i;
  }
  result[i] = '\0';
  return result;
}

char * baranov::inputString(std::istream & input, size_t & stringSize)
{
  const size_t bufferSize = 20;
  char * string = new char[bufferSize]{};
  char c = 0;
  size_t i = 0;
  input >> std::noskipws;
  while ((input >> c))
  {
    if (i == stringSize - 1)
    {
      try
      {
        char * expandedString = expandString(string, stringSize + bufferSize);
        delete[] string;
        string = expandedString;
      }
      catch (const std::bad_alloc & e)
      {
        delete[] string;
        throw;
      }
      stringSize += bufferSize;
    }
    string[i++] = c;
    if (c == '\n')
    {
      string[i - 1] = 0;
      break;
    }
  }
  if (string[0] == 0)
  {
    delete[] string;
    throw std::logic_error("Can not read string");
  }
  input >> std::skipws;
  return string;
}

