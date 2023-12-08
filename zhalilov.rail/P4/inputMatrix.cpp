#include "inputMatrix.hpp"

#include <iostream>

std::istream &zhalilov::inputMatrix(int matrix[], size_t rows, size_t cols, std::istream &input)
{
  for (size_t i = 0; i < rows * cols; i++)
  {
    if (!(input >> matrix[i]))
    {
      return input;
    }
  }
  return input;
}
