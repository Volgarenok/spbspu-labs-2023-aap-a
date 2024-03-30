#ifndef READ_ARRAY_H
#define READ_ARRAY_H

#include <cstddef>
#include <fstream>

namespace skuratov
{
  void readArray(std::istream& in, int* array, size_t rows, size_t cols);

}
#endif
