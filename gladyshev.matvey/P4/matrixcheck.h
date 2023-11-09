#ifndef MATRIXCHECK_H
#define MATRIXCHECK_H

#include <iostream>

namespace gladyshev
{
  bool isUpperTriangular(int ** matrix, size_t rows, size_t cols);
  bool isUpperTriangular(int matrix[100][100], size_t rows);
}

#endif
