#include "read_to_array.h"

size_t kovtun::readToArray(std::istream & in, int * array, size_t size, size_t toRead)
{
  size_t min = std::min(toRead, size);
  for (size_t i = 0; i < min; i++)
  {
    if (!(in >> array[i]))
    {
      return i;
    }
  }

  return min;
}
