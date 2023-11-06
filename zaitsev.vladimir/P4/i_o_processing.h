#ifndef I_O_PROCESSING_H
#define I_O_PROCESSING_H
#include <fstream>
#include <cstddef>

namespace zaitsev
{
  long checkArguments(int argc, char** argv);
  void readMatrix(std::ifstream& input, double* destination, size_t rows, size_t cols);
  std::ofstream& writeMatrix(std::ofstream& output, const double* destination, size_t rows, size_t cols);
}
#endif
