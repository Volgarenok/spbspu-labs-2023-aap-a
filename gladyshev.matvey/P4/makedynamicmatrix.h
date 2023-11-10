#ifndef MAKEDYNAMICMATRIX_H
#define MAKEDYNAMICMATRIX_H

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace gladyshev
{
  int goDynamicMatrix(std::fstream &input, int ** array, size_t rows, size_t cols);
  void freeMatrix(int ** matrix, size_t rows);
  void freeMatrix(int ** matrix, size_t rows, size_t cols);
}

#endif
