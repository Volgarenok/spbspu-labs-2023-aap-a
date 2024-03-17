#include "transformInputString.h"

#include <iomanip>
#include <stdexcept>

char* skuratov::transformInputString(std::istream& in, size_t& size)
{
  char* input = new char[size] {};
  char c = 0;
  size_t i = 0;
  in >> std::noskipws;
  while (in >> c)
  {
    if (!in)
    {
      throw std::runtime_error("Error input");
    }
    if (i == size - 1)
    {
      size += 10;
      char* newInput = new char[size] {};
      for (size_t j = 0; j < i; j++)
      {
        newInput[j] = input[j];
      }
      delete[] input;
      input = newInput;
    }
    input[i] = c;
    i++;
    if (c == '\n')
    {
      input[i - 1] = '\0';
      break;
    }
  }
  return input;
}
