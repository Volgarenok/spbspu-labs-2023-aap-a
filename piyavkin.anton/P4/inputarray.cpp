#include "inputarray.hpp"

size_t piyavkin::inputArray(std::istream & in, int * a, size_t s, size_t toread)
{
  for (size_t i = 0; i < std::min(toread, s); ++i)
  {
    if (!(in >> a[i]))
    {
      return i;
    }
  }
  return std::min(toread, s);
}
