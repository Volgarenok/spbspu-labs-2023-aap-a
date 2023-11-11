#include "matrixtransformation.hpp"

void marishin::matrixTransformation(int* matrix, int rows, int cols)
{
  int topRow = 0;
  int bottomRow = rows - 1;
  int leftCol = 0;
  int rightCol = cols - 1;
  int count = 1;

  while (topRow <= bottomRow && leftCol <= rightCol)
  {
    for (int row = bottomRow; row >= topRow; row--)
    {
      matrix[row * cols + leftCol] -= count;
      ++count;
    }
    leftCol++;
    for (int col = leftCol; col <= rightCol; col++)
    {
            matrix[topRow * cols + col] -= count;
            ++count;
    }
    topRow++;
    for (int row = topRow; row <= bottomRow; row++)
    {
            matrix[row * cols + rightCol] -= count;
            ++count;
    }
    rightCol--;
    if (topRow <= bottomRow)
    {
      for (int col = rightCol; col >= leftCol; col--)
      {
        matrix[bottomRow * cols + col] -= count;
        ++count;
      }
      bottomRow--;
    }
  }
}

void marishin::matrixEntry(std::ofstream& b, int* matrix, int rows, int cols)
{
  b << rows << cols;
  for (int i = 0; i < rows * cols; ++i)
  {
    b << matrix[i];
  }
}
