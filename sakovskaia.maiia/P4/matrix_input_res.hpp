#ifndef MATRIX_INPUT_ANS_HPP
#define MATRIX_INPUT_ANS_HPP
#include <cstddef>
#include <fstream>

namespace sakovskaia
{
  void inputMatrix(std::ifstream & input, int * a, size_t b);
  std::ostream & printAnswer(std::ostream & output, const int * a, size_t b);
}
#endif
