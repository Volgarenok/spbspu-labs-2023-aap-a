#include "arraycheck.hpp"

size_t marishin::checkArray(std::istream& input, int* matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (!(input >> matrix[i]))
    {
      return i;
    }
  }
  return rows * cols;
}
