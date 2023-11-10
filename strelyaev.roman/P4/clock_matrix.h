#ifndef CLOCK_MATRIX_H
#define CLOCK_MATRIX_H
#include <algorithm>
namespace strelyaev
{
  void clockwise(int * a, int rows, int columns);
  void matrixSubtraction(int * original, int * clock_matrix, int n);
}
#endif
