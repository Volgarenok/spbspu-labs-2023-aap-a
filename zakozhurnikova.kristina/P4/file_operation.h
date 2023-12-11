#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H
#include <cstddef>
#include <iosfwd>

namespace zakozhurnikova
{
  int checkArguments(int argc, const char* const* argv);
  void writeToDest(std::ostream& out, const int* matrix, size_t rows, size_t cols);
  void writeToMatrix(std::istream& in, int* matrix, size_t rows, size_t cols);
}
#endif
