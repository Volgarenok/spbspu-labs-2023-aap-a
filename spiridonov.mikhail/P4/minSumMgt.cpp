#include "getMinimumSum.hpp"
#include <limits>

size_t spiridonov::getMinimumSum(const int * matrix, size_t rows, size_t cols)
{
  int min_sum = matrix[cols - 1];

  for (unsigned int i = 1; i < rows; i++)
  {
    int sum = matrix[i * cols + cols - 1];

    for (unsigned int j = 0; j < cols && i + j < rows; j++)
    {
      sum += matrix[(i + j) * cols + cols - 1 - j];
    }

    if (sum < min_sum)
    {
      min_sum = sum;
    }
  }

  for (unsigned int i = 1; i < cols - 1; i++)
  {
    int sum = matrix[i + (cols - 1) * cols];

    for (unsigned int j = 0; j < rows && i + j < cols; j++)
    {
      sum += matrix[(rows - 1 - j) * cols + i + j];
    }

    if (sum < min_sum)
    {
      min_sum = sum;
    }
  }
  return min_sum;
}
