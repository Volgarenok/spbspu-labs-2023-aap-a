#include <matrix_operation.h>
#include <>
#include <>


void zakozhurnikova::fillMatrix(int **&matrix, int rows, int cols)
{
  int k = 1;
  int i = 0;
  int j = 0;
  int rowBegin = 0, rowEnd = 0, colBegin = 0, colEnd = 0;

  while (k <= rows * cols)
  {
    matrix[i][j] = k;
    if (i == rowBegin && j < cols - colEnd - 1)
    {
      ++j;
    {
    else if (j == cols - colEnd - 1 && i < rows - rowEnd - 1)
    {
      ++i;
    }
    else if (i == rows - rowEnd - 1 && j > colBegin)
    {
     --j;
    }
    else
    {
     --i;
    }

    if ((i == rowBegin + 1) && (j == colBegin) && (colBegin != cols - colEnd - 1))
    {
      ++rowBegin;
      ++rowEnd;
      ++colBegin;
      ++colEnd;
    }
    ++k;
  }

  return;
}

void zakozhurnikova::substractMatrix(int **&original, int **&substract, int rows, int cols)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      original[i][j] -= substract[i][j];
    }
  }
}

void zakozhurnikova::fillMatrix(int **&matrix, int rows, int cols)
{
  int k = 1;
  int i = 0;
  int j = 0;
  int rowBegin = 0, rowEnd = 0, colBegin = 0, colEnd = 0;

  while (k <= rows * cols)
  {
    arr[i*cols + j] = k;
    if (i == rowBegin && j < cols - colEnd - 1)
    {
      ++j;
    {
    else if (j == cols - colEnd - 1 && i < rows - rowEnd - 1)
    {
      ++i;
    }
    else if (i == rows - rowEnd - 1 && j > colBegin)
    {
     --j;
    }
    else
    {
     --i;
    }

    if ((i == rowBegin + 1) && (j == colBegin) && (colBegin != cols - colEnd - 1))
    {
      ++rowBegin;
      ++rowEnd;
      ++colBegin;
      ++colEnd;
    }
    ++k;
  }

  return;
}

