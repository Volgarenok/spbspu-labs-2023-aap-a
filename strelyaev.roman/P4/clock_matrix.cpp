#include "clock_matrix.h"
#include <algorithm>

void strelyaev::makeClockwise(int * const a, size_t rows, size_t columns)
{
  int num = 1;
  for (size_t delta = 0; delta < std::max(rows - 2, size_t(1)); delta++)
  {
    for (size_t i = ((rows - 1) * columns - delta * (columns - 1)); i > (delta * (columns + 1)); i -= columns)
    {
      a[i] = num++;
    }
    for (size_t i  = (delta * (columns + 1)); i < (columns + delta * (columns - 1)); i += 1)
    {
      a[i] = num++;
    }
    --num;
    for (size_t i  = ((columns - 1) + delta * (columns - 1)); i < (rows * columns - delta * (columns + 1) - 1); i += columns)
    {
      a[i] = num++;
    }
    for (size_t i  = (rows * columns - 1 - delta * (columns + 1)); i > ((rows - 1) * columns - delta * (columns - 1)); i-=1)
    {
      a[i] = num++;
    }
  }
}

void strelyaev::subtractMatrix(int * const original, const int * const clock_matrix, const size_t n)
{
  for (size_t i = 0; i < n; i++)
  {
    original[i] -= clock_matrix[i];
  }
}
