#ifndef ARRAY_CHECK_HPP
#define ARRAY_CHECK_HPP

#include <iostream>
#include <fstream>
#include "matrixtransformation.hpp"

namespace marishin
{
  size_t checkingArray(std::istream& input, int* matrix, const size_t rows, const size_t cols);
  int processingMatrix(std::istream& input, int* matrix, const size_t rows, const size_t cols, int num, const char* outputFilename);
}
#endif
