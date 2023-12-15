#ifndef READ_PRINT_MATRIX_HPP
#define READ_PRINT_MATRIX_HPP

#include <iosfwd>
namespace erohin
{
  void readMatrix(std::istream & input, int * matrix, size_t rows, size_t cols);
  void printMatrix(std::ostream & output, const int * matrix, size_t rows, size_t cols);
}
#endif
