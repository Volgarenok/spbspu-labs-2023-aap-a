#ifndef ZEROCMATRIX_H
#define ZEROMATRIX_H

#include <cstddef>
#include <limits>
#include <stdexcept>

namespace gladyshev
{
  bool isZeroMatrix(int ** matrix, size_t rows, size_t cols);
  bool isZeroMatrix(int matrix[100][100], size_t rows);
}
#endif
