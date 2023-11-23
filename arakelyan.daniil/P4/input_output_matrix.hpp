#ifndef INP_MATRIX_HPP
#define INP_MATRIX_HPP
#include <fstream>
#include <iomanip>
namespace arakelyan
{
  void inputMatrix(std::ifstream & input, int * matrix, size_t el);
  std::ofstream & outputTransformMatrix(std::ofstream & output, double * smoothed, size_t rows, size_t cols);
}
#endif
