#include "max_col_array.hpp"
#include <new>
int * namestnikov::maxColArray(size_t result, size_t cols, int * matrix)
{
  int * maxCol = nullptr;
  try
  {
    maxCol = new int[result];
  }
  catch (const std::bad_alloc &)
  {
    delete[] maxCol;
    throw;
  }
  for (size_t j = 0; j < cols; ++j)
  {
    maxCol[j] = matrix[j];
    for (size_t i = 0; i < result; i = i + cols)
    {
      if (matrix[j + i] > maxCol[j])
      {
        maxCol[j] = matrix[j + i];
      }
    }
  }
  return maxCol;
}
