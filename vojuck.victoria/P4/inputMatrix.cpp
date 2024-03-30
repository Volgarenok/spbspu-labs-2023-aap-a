#include <algorithm>
#include "inputMatrix.hpp"

size_t vojuck::inputArray(std::istream & in, long long int * array, size_t size, size_t toread)
{
  for (size_t i = 0; i < std::min(size, toread); ++i)
  {
    in >> array[i];
    if (!in)
    {
      return i;
    }
  }
  return std::min(size, toread);
}
