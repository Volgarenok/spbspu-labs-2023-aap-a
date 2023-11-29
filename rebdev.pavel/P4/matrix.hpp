#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <fstream>
#include <stddef.h>

namespace rebdev
{
  void filling(long long int * array, size_t rows, size_t colums, std::ifstream & inputFile);
  size_t findNumberOfLocalMax(long long int * arr, size_t rows, size_t colums);
}
#endif
