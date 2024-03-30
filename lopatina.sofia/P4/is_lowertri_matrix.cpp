#include "is_lowertri_matrix.hpp"

int lopatina::isLowerTriMatrix(int * matrix, size_t rows, size_t cols)
{
  if (rows != cols || rows == 0 || rows == 1)
  {
    return 0;
  }
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if (i < j && matrix[i * rows + j] != 0)
      {
        return 0;
      }
    }
  }
  return 1;
}
