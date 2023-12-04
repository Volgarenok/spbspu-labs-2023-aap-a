#include "maxSumDiagonal.hpp"
#include <algorithm>

long long int baranov::maxSumDiagonal(const int * matrix, size_t rows, size_t columns)
{
  size_t side = std::min(rows, columns);
  long long int result = 0;
  long long int current_sum = 0;

  for (size_t i = 0; i < (side - 1); ++i)
  {
    current_sum = 0;
    for (size_t j = 0; j <= i; ++j)
    {
      current_sum += matrix[i * columns - j * columns + j];
    }
    if (current_sum > result)
    {
      result = current_sum;
    }
  }

  for (size_t i = 1; i < side; ++i)
  {
    current_sum = 0;
    for (size_t j = 0; j < side - i; j++)
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

