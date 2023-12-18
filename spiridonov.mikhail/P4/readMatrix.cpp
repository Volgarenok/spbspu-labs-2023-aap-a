#include "readMatrix.hpp"
#include <iostream>

void spiridonov::readMatrix(std::istream & input, int * const matrix, const size_t rows, const size_t cols)
{
  for (size_t i = 0; i < rows * cols; i++)
  {
    if (!(input >> matrix[i]))
    {
      throw std::length_error("Error read matrix elements");
    }
  }
}
