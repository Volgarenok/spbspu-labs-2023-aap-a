#include "matrix.h"

void sMatrixInput(std::fstream & in, int * a, int e)
{
  for (int i = 0; i < e; i++)
  {
    if(!(in >> a[i]))
    {
      throw (std::logic_error("Unable to create matrix"));
    }
  }
}

void dMatrixInput(std::fstream & in, int * a, int e)
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

void printMatrix(std::fstream & out, int * a, int e)
{
  for (int i = 0; i < e; i++)
  {
    out << a[i];
  }
}