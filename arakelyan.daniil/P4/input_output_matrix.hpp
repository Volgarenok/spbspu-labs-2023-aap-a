#ifndef INPUT_OUTPUT_MATRIX_HPP
#define INPUT_OUTPUT_MATRIX_HPP
#include <iostream>
#include <cstddef>
namespace arakelyan
{
  void inputMatrix(std::istream & input, int * matrix, size_t el);
  std::ostream & outputMatrix(std::ostream & output, const double * matrix, size_t rows, size_t cols);
}
#endif
