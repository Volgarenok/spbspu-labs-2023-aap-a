#include <iostream>
#include <stdexcept>
#include "inputMatrix.hpp"

void inputMatrix(std::istream & input, int * matrix, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    if (!(input >> matrix[i]))
    {
      throw std::length_error("Can not read matrix element");
    }
  }
}

