#include "createMatrix.hpp"

int * petuhov::createMatrix(size_t rows, size_t cols)
{
  int * matrix = nullptr;
  matrix = new int[rows * cols];
  return matrix;
}