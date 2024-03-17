#include "readArray.hpp"

void marishin::readArray(std::istream& in, double* option, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    in >> option[i];
  }
}
