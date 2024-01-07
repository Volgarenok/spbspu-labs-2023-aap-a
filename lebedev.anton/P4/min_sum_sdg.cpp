#include "min_sum_sdg.hpp"

#include <algorithm>

long long lebedev::findMinSumSubdiags(const int matrix[], size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
    return 0;
  }
  if (rows == 1 && cols == 1)
  {
    return 0;
  }
  long long min_sum = 0;
  if (rows == 1)
  {
    min_sum = matrix[1];
    for (size_t i = 1; i < cols; ++i)
    {
      if (matrix[i] <= min_sum)
      {
        min_sum = matrix[i];
      }
    }
    return min_sum;
  }
  else if (rows != 1)
  {
    min_sum = matrix[0];
  }
  for (size_t i = 1; i < rows - 1; ++i)
  {
    long long sum = 0;
    size_t k = i;
    for (size_t j = 0; j < std::min(rows, cols); ++j)
    {
      if (k > 0)
      {
        sum += matrix[k * cols + j];
        if (k == 1 && j < cols - 1)
        {
          sum += matrix[j + 1];
        }
        --k;
      }
    }
    if (sum <= min_sum)
    {
      min_sum = sum;
    }
  }
  for (size_t j = 1; j < cols; ++j)
  {
    long long sum = 0;
    size_t k = j;
    for (size_t i = rows - 1; i > rows - std::min(rows, cols); --i)
    {
      if (k < cols)
      {
        sum += matrix[i * cols + k];
        if (i == 1 && k < cols - 1)
        {
          sum += matrix[k + 1];
        }
        ++k;
      }
    }
    if (sum <= min_sum)
    {
      min_sum = sum;
    }
  }
  return min_sum;
}
