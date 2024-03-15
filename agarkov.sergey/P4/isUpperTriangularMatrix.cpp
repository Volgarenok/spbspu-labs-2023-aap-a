#include "isUpperTriangularMatrix.hpp"
#include <cstddef>

bool agarkov::isUpperTriangularMatrix(const int* array, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size; j++)
    {
      if ((j < i) && (array[i * size + j] != 0))
      {
        return false;
      }
    }
  }
  return true;
}
