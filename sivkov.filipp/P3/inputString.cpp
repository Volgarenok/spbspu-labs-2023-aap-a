#include "inputString.hpp"
#include <cstdio>
#include <exception>

char* sivkov::addString(std::istream& in)
{
  const size_t initialSize = 20;
  const size_t incrementSize = 10;
  size_t size = initialSize;
  char* string = new char[size];

  if (!string)
  {
    return nullptr;
  }

  char c = 0;
  size_t i = 0;

  in >> std::noskipws;
  while ((in >> c) && (c != '\n'))
  {
    if (i == (size - 1))
    {
      size_t newSize = size + incrementSize;
      char* buffer = new char[newSize];
      if (!buffer)
      {
        delete[] string;
        return nullptr;
      }
      for (size_t j = 0; j < size; ++j)
      {
        buffer[j] = string[j];
      }
      delete[] string;
      string = buffer;
      size = newSize;
    }
    string[i++] = c;
  }
  string[i] = '\0';
  return string;
}
