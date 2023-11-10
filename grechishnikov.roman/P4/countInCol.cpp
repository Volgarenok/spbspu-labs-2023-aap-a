#include "countInCol.hpp"

size_t grechishnikov::countInCol(int * a, long long rows, long long col, size_t j)
{
  size_t inCol = 1;
  size_t inColMax = 1;
  for (long long i = 0; i < rows - 1; ++i)
  {
    if (a[i*col + j] == a[(i+1)*col + j])
    {
      inCol += 1;
      if (inCol > inColMax)
      {
        inColMax = inCol;
      }
    }
    else
    {
      inCol = 1;
    }
  }
  return inColMax;
}
