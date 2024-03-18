#include "trimatrix_check.hpp"

bool ishmuratov::lowerMatrixCheck(const int * matrix, size_t rows, size_t cols)
{
  bool isLower = true;
  if ((rows * cols == 0) || (rows != cols))
  {
    isLower = false;
  }
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = i + 1; j < cols; ++j)
    {
      if (matrix[i * cols + j] != 0)
      {
        isLower = false;
      }
    }
  }
  return isLower;
}
