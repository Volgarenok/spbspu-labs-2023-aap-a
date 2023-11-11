#ifndef READ_PRINT_MATRIX_HPP
#define READ_PRINT_MATRIX_HPP

#include <fstream>
namespace erohin
{
  void readMatrix(std::ifstream & input, int * matrix, const size_t & rows, const size_t & cols);
  void printMatrix(std::ofstream & output, int * matrix, const size_t & rows, const size_t & cols);
}
#endif
