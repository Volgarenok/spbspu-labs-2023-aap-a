#include "inputMatrix.hpp"
#include <iostream>
#include <stdexcept>

void baranov::inputMatrix(std::istream & input, int * matrix, size_t rows, size_t columns)
{
  for (size_t i = 0; i < rows * columns; ++i)
  {
    if (!(input >> matrix[i]))
    {
      throw std::length_error("Can not read matrix element");
    }
  }
}

