#include "min_row_array.hpp"

int * namestnikov::minRowArray(size_t result, size_t cols, int * matrix)
{
  int * minRow = nullptr;
  try
  {
    minRow = new int[result];
  }
  catch (const std::bad_alloc &)
  {
    if (minRow != nullptr)
    {
      delete[] minRow;
    }
    throw;
  }
  for (size_t i = 0; i < result; i = i + cols)
  {
    minRow[i]  = matrix[i];
    for (size_t j = 0; j < cols; ++j)
    {
      if (matrix[i + j] < minRow[i])
      {
        minRow[i] = matrix[i + j];
      }
    }
  }
  return minRow;
}
