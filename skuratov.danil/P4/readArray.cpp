#include "readArray.h"

#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>

void skuratov::readArray(std::istream& in, int* array, size_t rows, size_t cols)
{
  size_t size = rows * cols;
  for (size_t i = 0; i < size; i++)
  {
    if (!(in >> array[i]))
    {
      throw std::logic_error("Cannot read numbers");
    }
  }
}
