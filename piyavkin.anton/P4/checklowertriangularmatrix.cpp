#include "checklowertriangularmatrix.hpp"

bool piyavkin::checkLowerTriangularMatrix(size_t result, size_t rows, size_t cols, const int * matrix)
{
  if (rows <= 1 || rows != cols)
  {
    return false;
  }
  for (size_t i = 0; i < result; ++i)
  {
    if (i > ((i / cols) * (cols + 1)) && matrix[i] != 0)
    {
      return false;
    }
  }
  return true;
}
