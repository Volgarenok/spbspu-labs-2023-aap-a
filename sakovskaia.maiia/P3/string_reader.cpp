#include "string_reader.hpp"
#include <iostream>
#include <cstddef>

char * sakovskaia::readString(std::istream & input)
{
  size_t size = 10;
  char * buffer = new char[size];
  char c = 0;
  size_t i = 0;
  input >> std::noskipws;
  while ((input >> c) && (c != '\n'))
  {
    if (!input)
    {
      delete [] buffer;
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
          new_buffer[j] = buffer[j];
        }
        delete [] buffer;
        buffer = new_buffer;
      }
      catch (const std::bad_alloc &e)
      {
        delete [] buffer;
        throw;
      }
    }
    buffer[i++] = c;
  }
  buffer[i] = '\n';
  if ((buffer[0] == '\n') || (buffer[0] == '\0'))
  {
    delete [] buffer;
    throw std::logic_error("String is empty");
  }
  input >> std::skipws;
  return buffer;
}
