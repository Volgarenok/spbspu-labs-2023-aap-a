#ifndef GETMINIMUMSUM_HPP
#define GETMINIMUMSUM_HPP
#include <cstddef>
#include <fstream>

namespace spiridonov
{
  void readMatrix(std::ifstream& input, int * matrix, size_t size);
  size_t getMinimumSum(int * matrix, long long rows, long long cols);
}

#endif
