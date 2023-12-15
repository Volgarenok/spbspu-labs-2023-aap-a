#ifndef MATRIX_OPERATION_H
#define MATRIX_OPERATION_H
#include <cstddef>
#include <iosfwd>

namespace zakozhurnikova
{
  void fillMatrix(int* matrix, size_t rows, size_t cols);
  void substractMatrix(int* original, const int* substract, size_t rows, size_t cols);
}
#endif
