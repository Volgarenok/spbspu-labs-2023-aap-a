#ifndef MATRIX_TRANSFORM_HPP
#define MATRIX_TRANSFORM_HPP
#include <cstddef>
namespace ara
{
  double transformToSmoothMatrix(int * matrix, double * smoothed, size_t rows, size_t cols);
}
#endif
