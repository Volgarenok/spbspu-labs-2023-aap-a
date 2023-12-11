#ifndef MATRIX_TRANSFORMATION_HPP
#define MATRIX_TRANSFORMATION_HPP

#include <iostream>

namespace marishin
{
  void transformMatrix(int* matrix, size_t rows, size_t cols);
  void outputMatrix(std::ostream& b, const int* matrix, size_t rows, size_t cols);
}
#endif
