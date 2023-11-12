#include "nonzero.hpp"

bool piyavkin::NonZero(size_t result, int * matrix)
{
  for (size_t i = 0; i < result; ++i)
  {
    if (matrix[i] != 0)
    {
      return true;
    }
  }
  return false;
}
