#ifndef MATRIX_TRANSFORMATION_HPP
#define MATRIX_TRANSFORMATION_HPP

#include <iostream>

namespace marishin
{
  void transformMatrix(int* matrix, const size_t rows, const size_t cols);
  void inputMatrix(std::ostream& b, int* matrix, const size_t rows, const size_t cols);
}
#endif
