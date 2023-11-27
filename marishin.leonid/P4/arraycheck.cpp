#include "arraycheck.hpp"

size_t marishin::checkingArray(std::istream& input, int* matrix, const size_t rows, const size_t cols)
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
