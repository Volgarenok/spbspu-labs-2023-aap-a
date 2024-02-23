#include "ReadingMatrix.hpp"
#include <cstddef>
#include <fstream>
#include <stdexcept>

void serter::ReadingMatrix(std::ifstream& in, int matrix[], size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    in >> matrix[i];
    if (!in)
    {
      throw std::invalid_argument("Can't read matrix in array");
    }
  }
  return;
}

