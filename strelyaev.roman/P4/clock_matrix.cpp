#include "clock_matrix.h"
void strelyaev::clockwise(int * a, int rows, int columns)
{
  int num = 1;
  for (int delta = 0; delta < std::max(rows - 2, 1); delta++)
  {
    for (int i = ((rows - 1)*columns - delta * (columns - 1)); i > (delta * (columns + 1)); i -= columns)
    {
      a[i] = num++;
    }
    for (int i  = (delta * (columns + 1)); i < (columns + delta * (columns - 1)); i += 1)
    {
      a[i] = num++;
    }
    --num;
    for (int i  = ((columns - 1) + delta * (columns - 1)); i < (rows * columns - delta * (columns + 1) - 1); i += columns)
    {
      a[i] = num++;
    }
    for (int i  = (rows * columns - 1 - delta * (columns + 1)); i > ((rows - 1) * columns - delta * (columns - 1)); i-=1)
    {
      a[i] = num++;
    }
  }
}

void strelyaev::matrixSubtraction(int * original, int * clock_matrix, int n)
{
  for (int i = 0; i < n; i++)
  {
    original[i] -= clock_matrix[i];
  }
}
