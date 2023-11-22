#ifndef MATRIX_H
#define MATRIX_H
#include <fstream>
#include <stddef.h>
namespace strelyaev
{
  void inputMatrix(std::fstream & in, int * a, size_t e);
  void printMatrix(std::fstream & out, const int * a, size_t e);
}
#endif
