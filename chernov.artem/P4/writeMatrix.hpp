#ifndef WRITE_MATRIX_HPP
#define WRITE_MATRIX_HPP

#include <iostream>
#include <cstddef>

namespace chernov
{
  void writeMatrix(std::ostream& out, int* matrix, size_t rows, size_t cols);
}

#endif
