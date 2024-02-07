#include "matrix.hpp"
#include <iostream>

void sivkov::fillMatrix(std::istream& input, int* m, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    if (!(input >> m[i]))
    {
      throw std::logic_error("Cannot read numbers\n");
    }
  }
}
