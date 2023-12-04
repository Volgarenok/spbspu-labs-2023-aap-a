#ifndef MATRIX_TRANSFORMATION_HPP
#define MATRIX_TRANSFORMATION_HPP

#include <iostream>

namespace marishin
{
  void transformMatrix(int* matrix, size_t rows, size_t cols);
  void inputMatrix(std::ostream& b, int* matrix, size_t rows, size_t cols);
}
#endif
