#ifndef IOPROCESSING_HPP
#define IOPROCESSING_HPP
#include <cstddef>
#include <iostream>

namespace shabalin
{
  void matrixInput(std::istream& input, int* matrix, size_t countOfElements);
  void matrixOutput(std::ostream& output, const double* matrix, size_t rows, size_t cols);
}

#endif
