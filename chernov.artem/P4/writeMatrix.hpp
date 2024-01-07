#ifndef WRITE_MATRIX_HPP
#define WRITE_MATRIX_HPP

#include <cstddef>
#include <fstream>

namespace chernov
{
  void writeMatrix(std::ofstream& out, int* matrix, size_t rows, size_t cols);
}

#endif
