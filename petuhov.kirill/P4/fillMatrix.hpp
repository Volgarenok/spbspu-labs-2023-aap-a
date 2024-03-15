#ifndef FILL_MATRIX_HPP
#define FILL_MATRIX_HPP
#include <cstdlib>
#include <fstream>
namespace petuhov
{
  void fillMatrix(int *matrix, size_t rows, size_t cols, std::istream &input);
}
#endif
