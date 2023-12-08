#include "matrix.h"
#include <iostream>
void strelyaev::inputMatrix(std::istream & in, int * const a, const size_t e)
{
  for (size_t i = 0; i < e; i++)
  {
    if (!(in >> a[i]))
    {
      throw std::logic_error("Unable to create matrix");
    }
  }
}

std::ostream& strelyaev::printMatrix(std::ostream & out, const int * const a, const size_t e)
{
  if (e > 0)
  {
    out << a[0];
    for (size_t i = 1; i < e; i++)
    {
      out << " " << a[i];
    }
  }
  return out;
}
