#include "matrix.h"
#include <iostream>
void strelyaev::inputMatrix(std::istream & in, int * a, size_t e)
{
  for (size_t i = 0; i < e; i++)
  {
    if (!(in >> a[i]))
    {
      throw std::logic_error("Unable to create matrix");
    }
  }
}

void strelyaev::printMatrix(std::ostream & out, int * a, size_t e)
{
  for (size_t i = 0; i < e; i++)
  {
    out << a[i] << " ";
  }
}
