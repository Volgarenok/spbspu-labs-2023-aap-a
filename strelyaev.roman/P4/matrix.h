#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include <ostream>
namespace strelyaev
{
  void inputMatrix(std::istream & in, int * a, size_t e);
  std::ostream& printMatrix(std::ostream & out, const int * a, size_t e);
}
#endif
