#include "writeMatrix.hpp"

#include <iostream>
#include <cstddef>

void chernov::writeMatrix(std::ostream& out, int* matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      if (i == rows - 1 && j == cols - 1)
      {
        out << matrix[i * cols + j];
      }
      else
      {
        out << matrix[i * cols + j] << " ";
      }
      if (!out)
      {
        throw std::invalid_argument("Error output matrix");
      }
    }
  }
}
