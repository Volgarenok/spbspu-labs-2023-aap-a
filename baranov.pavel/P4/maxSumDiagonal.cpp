#include <algorithm>
#include "maxSumDiagonal.hpp"

int maxSumDiagonal(int * matrix, unsigned int rows, unsigned int columns)
{
  unsigned int side = std::min(rows, columns);
  int result = 0;
  int current_sum = 0;

  for (unsigned int i = 0; i < (side - 1); ++i)
  {
    current_sum = 0;
    for (unsigned int j = 0; j <= i; ++j)
    {
      current_sum += matrix[i * columns - j * columns + j];
    }
    if (current_sum > result)
    {
      result = current_sum;
    }
  }

  for (unsigned int i = 1; i < side; ++i)
  {
    current_sum = 0;
    for (unsigned int j = 0; j < side - i; j++)
    {
      current_sum += matrix[i * columns + (side - 1) + j * columns - j];
    }
    if (current_sum > result)
    {
      result = current_sum;
    }
  }
  return result;
}

