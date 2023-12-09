#ifndef I_O_PROCESSING_H
#define I_O_PROCESSING_H
#include <fstream>
#include <cstddef>

namespace zaitsev
{
  long checkArguments(int argc, const char* const* argv);
  std::istream& readMatrix(std::istream& input, int* destination, size_t rows, size_t cols);
  std::ostream& writeMatrix(std::ostream& output, const double* destination, size_t rows, size_t cols);
}
#endif
