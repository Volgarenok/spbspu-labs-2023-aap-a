#include "count_diag_nzero.hpp"

size_t lopatina::countDiagWithoutZero(int * matrix, size_t rows, size_t cols)
{
  if (rows != cols || rows == 0)
  {
    return 0;
  }
  size_t counter = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    if (i == 0)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        if (i != j)
        {
          counter += 1;
          size_t n1 = i, n2 = j;
          for (size_t k = 0; k < cols - j; ++k)
          {
            if (matrix[n1 * rows + n2] == 0)
            {
              counter -= 1;
              break;
            }
            n1 += 1;
            n2 += 1;
          }
        }
      }
    }
    else if (i > 0)
    {
      counter += 1;
      size_t n1 = i;
      for (size_t k = 0; k < rows - i; ++k)
      {
        if (matrix[n1 * rows + k] == 0)
        {
          counter -= 1;
          break;
        }
        n1 += 1;
      }
    }
  }
  return counter;
}
