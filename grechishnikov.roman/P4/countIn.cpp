#include "countIn.hpp"

size_t countInCol(const int * a, size_t rows, size_t cols, size_t j)
{
  size_t inCol = 1;
  size_t inColMax = 1;
  for (size_t i = 0; i < rows - 1; ++i)
  {
    if (a[i * cols + j] == a[(i + 1) * cols + j])
    {
      inCol++;
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

size_t grechishnikov::countInMatr(const int * a, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0)
  {
   return 0;
  }
  size_t maxNumCol = 0;
  size_t maxPodr = 0;
  for (size_t i = 0; i < cols; ++i)
  {
    if (maxPodr < countInCol(a, rows, cols, i))
    {
      maxPodr = countInCol(a, rows, cols, i);
      maxNumCol = i + 1;
    }
  }
  return maxNumCol;
}
