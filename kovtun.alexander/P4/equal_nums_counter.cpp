#include "equal_nums_counter.h"

size_t kovtun::countEqualInColumns(const int * matrix, size_t rows, size_t cols)
{
  size_t result = cols;

  if (rows == 1)
  {
    return 0;
  }

  for (size_t i = 0; i < cols; i++)
  {
    int previous = matrix[i];
    for (size_t j = 1; j < rows; j++)
    {
      if (matrix[j * cols + i] == previous)
      {
        result--;
        break;
      }

      previous = matrix[j * cols + i];
    }
  }

  return result;
}
