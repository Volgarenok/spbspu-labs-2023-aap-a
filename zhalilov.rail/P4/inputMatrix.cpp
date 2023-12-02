#include "inputMatrix.hpp"

#include <iostream>

std::istream &zhalilov::inputMatrix(int matrix[], int rows, int cols, std::istream &input)
{
  for (int i = 0; i < rows * cols; i++)
  {
    if (!(input >> matrix[i]))
    {
      return input;
    }
  }
  return input;
}
