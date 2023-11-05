#include "matrix.h"
#include <algorithm>

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

void matrixSubtraction(int * original, int * reverse, int n)
{
  for (int i = 0; i < n; i++)
  {
    original[i] -= reverse[i];
  }
}

void clockwise(int * a, int rows, int columns)
{
  int start = (rows-1) * columns + 0;
  int num = 1;
  for (int delta = 0; delta < std::max(rows - 2, 1); delta++)
  {
    for (int i = (rows-1)*columns - delta*(columns-1); i > delta*(columns+1); i-=columns)
    {
      a[i] = num++;
    }
    for (int i  = 0 + delta*(columns+1); i < columns + delta*(columns-1); i+=1)
    {
      a[i] = num++;
    }
    --num;
    for (int i  = (columns-1) + delta*(columns-1); i < rows*columns - delta*(columns+1) - 1; i+=columns)
    {
      a[i] = num++;
    }
    for (int i  = rows*columns - 1 - delta*(columns+1); i > (rows-1) * columns - delta*(columns-1); i-=1)
    {
      a[i] = num++;
    }
  }
}