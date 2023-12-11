#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP

#include <cstddef>
#include <fstream>

namespace chistyakov
{
  size_t inputArray(std::istream & input, int * array, size_t size, size_t sizeToRead);
}

#endif
