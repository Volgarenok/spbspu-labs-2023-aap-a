#include <iostream>

int main(int argc, char* argv[]))
{
  size_t rows = 0;
  size_t cols = 0;
  std::cin >> rows >> cols;
  size_t matrixSize = rows * cols;
  int* matrix = new int[matrixSize];
  for (size_t i = 0; i < matrixSize; i++)
  {
    std::cin >> matrix[i];
  }
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

  for (size_t j = 0; j < matrixSize; j++)
  {
    std::cout << matrix[j] << " ";
  }
  delete[] matrix;
}
