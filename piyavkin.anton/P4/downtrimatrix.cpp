#include "downtrimatrix.hpp"

bool DownTriMatrix(size_t result, int rows, int cols, int * matrix)
{
  if (rows == cols && rows > 1)
  {
    for (size_t i = 0; i < result; ++i)
    {
      if (i > ((i / cols) * (cols + 1)) && matrix[i] != 0)
      {
        return false;
      }
    }
    return true;
  }
  else
  {
    return false;
  }
}
