#include "createMatrix.hpp"
#include "destroyMatrix.hpp"


int * petuhov::createMatrix(size_t rows, size_t cols)
{
  int * matrix = nullptr;

  matrix = new int[rows * cols];
  return matrix;
}
