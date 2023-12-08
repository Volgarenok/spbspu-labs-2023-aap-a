#include "matrixtransformation.hpp"

void marishin::transformMatrix(int* matrix, size_t rows, size_t cols)
{
  int topRow = 0;
  int bottomRow = rows - 1;
  int leftCol = 0;
  int rightCol = cols - 1;
  size_t count = 1;

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

void marishin::outputMatrix(std::ostream& b, const int* matrix, size_t rows, size_t cols)
{
  b << rows << " " << cols;
  for (size_t i = 0; i < rows * cols; ++i)
  {
    b << " " << matrix[i];
  }
}
