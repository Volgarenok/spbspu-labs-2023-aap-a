#ifndef READTHEARRAY_H
#define READTHEARRAY_H
#include <cstddef>
#include <iostream>

namespace skuratov
{
  std::istream& readTheArray(std::istream& in, size_t sizeOfFileArray, int* fileArray);
}

#endif
