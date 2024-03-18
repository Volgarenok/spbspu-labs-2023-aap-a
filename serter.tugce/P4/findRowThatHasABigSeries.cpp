#include "findRowThatHasABigSeries.hpp"
#include <cstddef>

size_t serter::findRowThatHasABigSeries(const int matrix[], size_t rows, size_t cols)
{
  size_t result = 0;
  size_t maxSeries = 0;

  for (size_t i = 0; i < rows; ++i)
  {
    size_t currentSeries = 1;

    for (size_t j = 1; j < cols; ++j)
    {
      if (matrix[i * cols + j] == matrix[i * cols + j - 1])
      {
        ++currentSeries;
      }
      else
      {
        if (currentSeries > maxSeries)
        {
          maxSeries = currentSeries;
          result = i;
        }
        currentSeries = 1;
      }
    }

    if (currentSeries > maxSeries)
    {
      maxSeries = currentSeries;
      result = i;
    }
  }

  return result;
}

