#include "inputMatrix.hpp"
#include <stdexcept>

void grechishnikov::inputMatrix(std::istream &in, int * a, size_t max)
{
  for (size_t i = 0; i < max; ++i)
  {
    if (!(in >> a[i]))
    {
      throw std::logic_error("Cannot read a matrix");
    }
  }
}
