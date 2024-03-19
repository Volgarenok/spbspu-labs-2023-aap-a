#ifndef OUTPUT_H
#define OUTPUT_H

#include <cstddef>
#include <fstream>

namespace skopchenko
{
  void outputInt(std::ostream& oFile, const int *matrix, size_t rows, size_t cols);
  void outputDouble(std::ostream& oFile, const double *matrix, size_t rows, size_t cols);
}

#endif
