#include "transformInputString.hpp"
#include <iostream>
#include <cstddef>
#include <iomanip>

char* transformInputString(char* input, size_t size)
{
  char c = 0;
  size_t i = 0;
  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    if (i == 0 && c == '\n')
    {
      std::cerr << "Error input";
      return nullptr;
    }
    if (i == size - 1)
    {
      size *= 2;
      char* newinput = new char[size];
      for (size_t g = 0; g < i; g++)
      {
        newinput[g] = input[g];
      }
      delete[] input;
      input = newinput;
    }
    input[i++] = c;
    if (c == '\n')
    {
      input[i - 1] = '\0';
      break;
    }
  }
  return input;
}
