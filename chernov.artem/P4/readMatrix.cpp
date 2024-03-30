#include "readMatrix.hpp"

#include <iostream>
#include <cstddef>
#include <stdexcept>

void chernov::readMatrix(std::istream& input, int* matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    input >> matrix[i];
    if (!input)
    {
      throw std::invalid_argument("Input error");
    }
  }
}
