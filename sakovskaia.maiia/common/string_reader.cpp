#include "string_reader.hpp"
#include <iostream>
#include <cstddef>

char * sakovskaia::readString(std::istream & input)
{
  size_t size = 10;
  char * string = new char[size];
  char c = 0;
  size_t i = 0;
  input >> std::noskipws;
  while ((input >> c) && (c != '\n'))
  {
    if (!input)
    {
      delete [] string;
      throw std::logic_error("Error in input");
    }
    if (i == (size - 1))
    {
      size += 10;
      try
      {
        char * new_buffer = new char[size]{};
        for (size_t j = 0; j < i; j++)
        {
          new_buffer[j] = string[j];
        }
        delete [] string;
        string = new_buffer;
      }
      catch (const std::bad_alloc &e)
      {
        delete [] string;
        throw;
      }
    }
    string[i++] = c;
  }
  string[i] = '\n';
  input >> std::skipws;
  return string;
}
