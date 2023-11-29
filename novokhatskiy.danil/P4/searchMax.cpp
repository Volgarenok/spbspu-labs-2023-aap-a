#include "searchMax.hpp"
#include <algorithm>

int novokhatskiy::searchMax(int matrix[], size_t rows, size_t cols)
{
  int max = 0;
  size_t size = std::min(rows,cols);
  if ((rows != 0) && (cols != 0))
  {
    for (size_t i = 0; i < size - 1; i++)
    {
      int sum = 0;
      for (size_t j = 0; j <= i * cols; j += cols -1)
      {
        sum += matrix[j];
      }
      if (sum > max)
      {
        max = sum;
      }
    }
    for (size_t i = size - 1 + cols; i < rows * cols; i += cols)
    {
      int sum = 0;
      for (size_t j = i; j < rows * cols; j += cols - 1)
      {
        sum += matrix[j];
      }
      if (sum > max)
      {
        max = sum;
      }
    }
  }
  return max;
}
