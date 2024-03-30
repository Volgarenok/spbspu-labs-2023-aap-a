#ifndef READ_MATRIX_HPP
#define READ_MATRIX_HPP

#include <iostream>
#include <cstddef>

namespace chernov
{
  void readMatrix(std::istream& input, int* matrix, size_t rows, size_t cols);
}

#endif
