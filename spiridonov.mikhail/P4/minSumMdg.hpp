#ifndef MINSUMMDG_HPP
#define MINSUMMDG_HPP
#include <cstddef>
#include <fstream>

namespace spiridonov
{
  void readMatrix(std::ifstream& input, int * matrix, size_t rows, size_t cols);
}

#endif
