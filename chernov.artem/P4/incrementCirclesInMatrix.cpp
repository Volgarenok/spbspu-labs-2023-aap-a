#include "incrementCirclesInMatrix.hpp"

#include <algorithm>
#include <cstddef>

int* chernov::incrementCirclesInMatrix(int* matrix, size_t rows, size_t cols)
{
  size_t n = std::min(rows, cols) / 2 + std::min(rows, cols) % 2;
  for (size_t p = 0; p < n; p++)
  {
    size_t value = p + 1;

    for (size_t i = p; i < cols - p; i++)
    {
      if (p * cols + i == (rows - p - 1) * cols + i)
      {
        matrix[p * cols + i] += value;
      }
      else
      {
        matrix[p * cols + i] += value;
        matrix[(rows - p - 1) * cols + i] += value;
      }
    }

    for (size_t i = p + 1; i < rows - p - 1; i++)
    {
      if (i * cols + (cols - p - 1) == i * cols + p)
      {
        matrix[i * cols + p] += value;
      }
      else
      {
        matrix[i * cols + (cols - p - 1)] += value;
        matrix[i * cols + p] += value;
      }
    }
  }
  return matrix;
}
