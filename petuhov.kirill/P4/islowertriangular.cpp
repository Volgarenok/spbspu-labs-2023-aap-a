#include "islowertriangular.hpp"

bool petuhov::isLowerTriangular(const int* matrix, size_t rows, size_t cols)
{
  bool isLowerTriangularMatrix = true;

  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = i + 1; j < cols; ++j)
    {
      if (matrix[i * cols + j] != 0)
      {
        isLowerTriangularMatrix = false;
        break;
      }
    }
    if (!isLowerTriangularMatrix)
    {
      break;
    }
  }

  return isLowerTriangularMatrix;
}
