#ifndef SADDLE_POINTS_COUNTER_H
#define SADDLE_POINTS_COUNTER_H
#include <cstddef>

namespace namestnikov
{
  int * getMaxColArray(size_t result, size_t cols, const int * matrix);
  int * getMinRowArray(size_t result, size_t cols, const int * matrix);
  size_t countSaddlePoints(const int * matrix, const int * maxCol, const int * minRow, size_t result, size_t cols);
}

#endif
