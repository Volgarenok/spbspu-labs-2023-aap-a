#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include <ostream>
namespace strelyaev
{
  void inputMatrix(std::istream & in, int * a, size_t e);
  void printMatrix(std::ostream & out, int * a, size_t e);
}
#endif
