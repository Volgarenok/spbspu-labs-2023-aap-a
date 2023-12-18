#include "checknonzero.hpp"

bool piyavkin::checkNonZero(size_t result, const int * matrix)
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
