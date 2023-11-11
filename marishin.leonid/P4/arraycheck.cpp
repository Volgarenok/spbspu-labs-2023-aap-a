#include "arraycheck.hpp"

bool marishin::arrayCheck(std::istream& n, int* matrix, int rows, int cols, int num)
{
  if (num == 1)
  {
    for (int i = 0; i < rows * cols; ++i)
    {
      if (!(n >> matrix[i]))
      {
        return false;
      }
      return true;
    }
  }
  else
  {
    for (int i = 0; i < rows * cols; ++i)
    {
      if (!(n >> matrix[i]))
      {
        return false;
      }
      return true;
    }
  }
}
