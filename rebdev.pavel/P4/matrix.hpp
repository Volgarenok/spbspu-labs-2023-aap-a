#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <fstream>
#include <cstddef>

namespace rebdev
{
  size_t fillTheMatrix(long long int * array, size_t rows, size_t colums, std::ifstream & inputFile);
  size_t findNumberOfLocalMax(long long int * arr, size_t rows, size_t colums);
}
#endif
