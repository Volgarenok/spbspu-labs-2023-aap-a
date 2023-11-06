#ifndef I_O_PROCESSING_H
#define I_O_PROCESSING_H
#include <fstream>
#include <cstddef>

namespace zaitsev
{
  long checkArguments(int argc, char** argv);
  void readMatrix(std::ifstream&, double*, size_t);
  std::ofstream& writeMatrix(std::ofstream&, const double*, size_t, size_t);
}
#endif
