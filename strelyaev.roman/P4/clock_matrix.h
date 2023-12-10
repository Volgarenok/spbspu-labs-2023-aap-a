#ifndef CLOCK_MATRIX_H
#define CLOCK_MATRIX_H
#include <cstddef>
namespace strelyaev
{
  void makeClockwise(int * a, size_t rows, size_t columns);
  void subtractMatrix(int * original, const int * clock_matrix, size_t n);
}
#endif
