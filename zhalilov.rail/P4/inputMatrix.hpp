#ifndef INPUT_MATRIX_HPP
#define INPUT_MATRIX_HPP

#include <iosfwd>
#include <cstddef>

namespace zhalilov
{
  std::istream &inputMatrix(int matrix[], size_t rows, size_t cols, std::istream &input);
}

#endif
