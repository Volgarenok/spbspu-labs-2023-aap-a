#include "matrix.h"

void sMatrix (std::istream & in, int * a, int e)
{
  for (int i = 0; i < e; i++)
  {
    if(!(in >> a[i]))
    {
      throw (std::logic_error("Unable to create matrix"));
    }
  }
}

void dMatrix (std::istream & in, int * a, int e)
{
  for (int i = 0; i < e; i++)
  {
    if(!(in >> a[i]))
    {
      delete [] a;
      throw (std::logic_error("Unable to create matrix"));
    }
  }
}