#include "matrixchecktri.h"

bool gladyshev::isUpperTriangular(const int * matrix, size_t rows, size_t cols)
{
  bool checkside = true;
  for (size_t i = 1; i < rows; ++i)
  {
    for (size_t j = 0; j < i; ++j)
    {
      if (matrix[rows * i + j] != 0)
      {
        checkside = false;
      }
    }
  }
  if (checkside)
  {
    return true;
  }
  else
  {
    for (size_t i = 1; i < cols; ++i)
    {
      for (size_t j = 0; j < i; ++j)
      {
        if (matrix[rows * i + rows - j - 1] != 0)
        {
          return false;
        }
      }
    }
  }
  return true;
}
