#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <fstream>
#include <cstddef>

namespace sakovskaia
{
  void countCounterclockwiseMatrix(int * a, size_t rows, size_t columns);
  void countAnswer(int * input_matrix, const int * counterclockwise_matrix, size_t size);
}
#endif
