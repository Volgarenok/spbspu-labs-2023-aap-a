#include "read_print_matrix.hpp"
#include <iostream>

void erohin::readMatrix(std::istream & input, int * matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      input >> matrix[rows * i + j];
    }
  }
}

void erohin::printMatrix(std::ostream & output, const int * matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      output << matrix[rows * i + j];
      if ((i + 1) < rows || (j + 1) < cols)
      {
        output << " ";
      }
    }
  }
}
