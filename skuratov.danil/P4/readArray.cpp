#include "readArray.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

int* skuratov::readArray(std::ifstream& in, int array[], const size_t& rows, const size_t& cols)
{
  size_t count = 0;

  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!(in >> array[i]))
    {
      std::cerr << "Error reading element at index\n";
      return nullptr;
    }
    count++;
  }

  if (count != rows * cols)
  {
    std::cerr << "Error\n";
    return nullptr;
  }
  return array;
}
