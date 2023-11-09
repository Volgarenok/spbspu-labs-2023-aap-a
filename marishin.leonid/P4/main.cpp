#include <iostream>

int main()
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
  {}
}
