#include "writeMatrix.hpp"

#include <cstddef>
#include <fstream>

void chernov::writeMatrix(std::ofstream& out, int* matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      out << matrix[i * cols + j] << " ";
      if (!out)
      {
        throw std::invalid_argument("Error output matrix");
      }
    }
  }
}
