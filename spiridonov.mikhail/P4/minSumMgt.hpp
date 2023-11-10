#ifndef MINSUMMGT_HPP
#define MINSUMMGT_HPP
#include <cstddef>
#include <fstream>

namespace spiridonov
{
  void readMatrix(std::ifstream& input, int * matrix, size_t size);
}

#endif
