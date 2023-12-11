#ifndef INPUT_OUTPUT_MATRIX_HPP 
#define INPUT_OUTPUT_MATRIX_HPP
#include <cmath>
#include <fstream>
namespace arakelyan
{
  void inputMatrix(std::istream & input, int * matrix, size_t el);
  std::ostream & outputMatrix(std::ostream & output, double * matrix, size_t rows, size_t cols);
}
#endif
