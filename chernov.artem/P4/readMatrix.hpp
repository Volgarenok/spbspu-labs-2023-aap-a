#ifndef READ_MATRIX_HPP
#define READ_MATRIX_HPP

#include <cstddef>
#include <fstream>

namespace chernov
{
  void readMatrix(std::ifstream& input, int* matrix, const size_t& rows, const size_t& cols);
}

#endif
