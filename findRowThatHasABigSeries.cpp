#include "findRowThatHasABigSeries.hpp"
#include <cstddef>

size_t serter::findRowThatHasABigSeries(int matrix[], size_t rows, size_t cols)
{
  size_t result = -1;
  for (size_t i = 0; i < rows; ++i)
  {
    int currentSeries = 1;
    int maxSeries = 1;
    for (size_t j = 1; j < cols; ++j)
    {
      if (matrix[i * cols + j] == matrix[i * cols + j - 1])
      {
        ++currentSeries;
        if (currentSeries > maxSeries)
        {
          maxSeries = currentSeries;
        }
      }
      else
      {
        currentSeries = 1;
      }
    }
    if (maxSeries > result)
    {
      result = i;
    }
  }
  return result;
}
