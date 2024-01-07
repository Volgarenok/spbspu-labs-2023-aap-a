#include "findLongestSeriesRow.h"

int skuratov::findLongestSeriesRow(int* array, size_t rows, size_t cols)
{
  int maxSeriesLength = 1;
  int currentSeriesLength = 1;
  int maxSeriesRow = 0;
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
