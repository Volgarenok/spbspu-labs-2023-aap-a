#include "findMaxSum.hpp"
#include <algorithm>

int vojuck::findMaxSum(const long long * array, size_t rows, size_t cols)
{
  int maxSum = 0;
  for (size_t i = 0; i < rows; i++)
  {
    int sum1 = 0;
    int sum2 = 0;
    for (size_t j = 0; j < cols - i; j++)
    {
      sum1 += array[j + rows * j + i];
      sum2 += array[j + i + cols * j];
    }
    maxSum = std::max(maxSum, std::max(sum1, sum2));
  }
  return maxSum;
}
