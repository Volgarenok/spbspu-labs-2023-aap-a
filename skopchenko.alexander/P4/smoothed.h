#ifndef SMOOTHED_H
#define SMOOTHED_H

#include <cstddef>

namespace skopchenko
{
  void makeSmoothMatrix(const int *matrix, double *smoothMatrix, size_t rows, size_t cols);
}

#endif
