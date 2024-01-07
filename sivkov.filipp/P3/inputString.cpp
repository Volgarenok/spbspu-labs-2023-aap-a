#include "inputString.hpp"
#include <iostream>

char* sivkov::addString(size_t& size)
{
  char c = 0;
  size_t k = 0;
  size_t count = 0;
  std::cin >> std::noskipws;

  char* string = new char[size];
  if (!string)
  {
    std::cerr << "Error with array\n";
    return nullptr;
  }

  while (std::cin >> c)
  {
    if ((k == 0) && (c == '\n'))
    {
      delete[] string;
      return nullptr;
    }

    string[count++] = c;
    k++;

    if (c == '\n')
    {
      string[k - 1] = '\0';
      break;
    }
    else
    {
      if (k == size - 1)
      {
        size *= 2;
        char* newstring = new char[size];
        if (!newstring)
        {
          std::cerr << "Error with array\n";
          delete[] string;
          return nullptr;
        }
        for (size_t j = 0; j < k; j++)
        {
          newstring[j] = string[j];
        }
        delete[] string;
        string = newstring;
      }
    }
  }
  return string;
}
