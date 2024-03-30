#include "countNonZeroDiagonals.hpp"

#include <cstddef>

size_t chernov::countNonZeroDiagonals(const int* matrix, size_t cols, size_t rows)
{
  size_t counter = (rows - 1) * 2;
  for (size_t i = 1; i < rows; i++)
  {
    for (size_t j = 0; j < rows - i; j++)
    {
      if (matrix[rows * j + j + i] == 0)
      {
        counter -= 1;
        break;
      }
    }
  }
  for (size_t i = 1; i < cols; i++)
  {
    for (size_t j = 0; j < cols - i; j++)
    {
      if (matrix[cols * j + j + i + (cols - 1) * i] == 0)
      {
        counter -= 1;
        break;
      }
    }
  }
  return counter;
}
