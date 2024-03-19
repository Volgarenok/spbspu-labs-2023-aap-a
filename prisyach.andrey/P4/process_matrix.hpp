#ifndef PROCESS_MATRIX_HPP
#define PROCESS_MATRIX_HPP

#include <cstddef>
#include <istream>

namespace prisyach
{
  size_t findMaxSequence(const int * matrix, size_t rows, size_t cols);

  void transformMatrix(int* matrix, size_t rows, size_t cols);

  void readMatrix(std::istream & input, int * matrix, size_t rows, size_t cols);

  void outputMatrix(std::ostream & input, int * matrix, size_t rows, size_t cols);
}
#endif
