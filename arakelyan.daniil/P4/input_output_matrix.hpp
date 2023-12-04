#ifndef INP_MATRIX_HPP
#define INP_MATRIX_HPP
#include <iostream>
#include <cmath>
namespace arakelyan
{
  void inputMatrix(std::istream & input, int * matrix, size_t el);
  std::ostream & outputMatrix(std::ostream & output, double * matrix, size_t rows, size_t cols);
}
#endif
