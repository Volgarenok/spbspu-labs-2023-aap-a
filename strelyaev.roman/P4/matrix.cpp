#include "matrix.h"

void strelyaev::inputMatrix(std::fstream & in, int * a, size_t e)
{
  for (int i = 0; i < e; i++)
  {
    if (!(in >> a[i]))
    {
      throw (std::logic_error("Unable to create matrix"));
    }
  }
}

void strelyaev::printMatrix(std::fstream & out, int * a, size_t e)
{
  for (int i = 0; i < e; i++)
  {
    out << a[i];
  }
}
