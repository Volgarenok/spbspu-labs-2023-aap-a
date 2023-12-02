#include "get_result.hpp"

size_t namestnikov::getResult(const int * matrix, const int * maxCol, const int * minRow, size_t result, size_t cols)
{
  size_t count = 0;
  for (size_t i = 0; i < result; i = i + cols)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if ((matrix[i + j] == minRow[i]) && (matrix[i + j] == maxCol[j]))
      {
        ++count;
      }
    }
  }
  return count;
}

