#include "read_print_matrix.hpp"
#include <fstream>
#include <stdexcept>

void erohin::readMatrix(std::ifstream & input, int * matrix, const size_t & rows, const size_t & cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      input >> matrix[rows * i + j];
    }
  }
  if (!input)
  {
    throw std::invalid_argument("Invalid value of matrix element");
  }
  return;
}

void erohin::printMatrix(std::ofstream & output, int * matrix, const size_t & rows, const size_t & cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      output << " " << matrix[rows * i + j];
    }
  }
  return;
}
