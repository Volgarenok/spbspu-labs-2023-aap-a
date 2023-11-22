#include "zeromatrix.h"

bool gladyshev::isZeroMatrix(int * matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    if (matrix[i] != 0)
    {
      return false;
    }
  }
  return true;
}
