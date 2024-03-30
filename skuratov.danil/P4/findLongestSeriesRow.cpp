#include "findLongestSeriesRow.h"

#include <cstddef>

size_t skuratov::findLongestSeriesRow(const int* array, size_t rows, size_t cols)
{
  size_t maxSeriesLength = 1;
  size_t currentSeriesLength = 1;
  size_t maxSeriesRow = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    currentSeriesLength = 1;
    for (size_t j = 1; j < cols; ++j)
    {
      if (array[i * cols + j] == array[i * cols + j - 1])
      {
        currentSeriesLength++;
      }
      else
      {
        if (currentSeriesLength > maxSeriesLength)
        {
          maxSeriesLength = currentSeriesLength;
          maxSeriesRow = i;
        }
        currentSeriesLength = 1;
      }
    }
    if (currentSeriesLength > maxSeriesLength)
    {
      maxSeriesLength = currentSeriesLength;
      maxSeriesRow = i;
    }
  }
  return maxSeriesRow + 1;
}
