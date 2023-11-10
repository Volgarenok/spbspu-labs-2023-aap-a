#include "getMinimumSum.hpp"
#include <limits>

void spiridonov::readMatrix(std::ifstream& input, int* matrix, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    input >> matrix[i];
  }
}

int min_sum = std::numeric_limits<int>::max();

size_t spiridonov::getMinimumSum(int * matrix, long long rows, long long cols)
{
  int min_sum = matrix[cols - 1];

  for (long long i = 1; i < rows; i++)
  {
    int sum = matrix[i * cols + cols - 1];

    for (long long j = 0; j < cols && i + j < rows; j++)
    {
      sum += matrix[(i + j) * cols + cols - 1 - j];
    }

    if (sum < min_sum)
    {
      min_sum = sum;
    }
  }

  for (long long i = 1; i < cols - 1; i++)
  {
    int sum = matrix[i + (cols - 1) * cols];

    for (long long j = 0; j < rows && i + j < cols; j++)
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
