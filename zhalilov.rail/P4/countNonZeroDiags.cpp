#include "countNonZeroDiags.hpp"

#include <algorithm>

size_t zhalilov::countNonZeroDiags(const int matrix[], size_t rows, size_t cols)
{
  size_t count = 0;
  size_t sqrLength = std::min(rows, cols);
  size_t lineLength = sqrLength * sqrLength;
  bool isUpperZero = false;
  bool isLowerZero = false;
  for (size_t i = 1; i < sqrLength; i++)
  {
    for (size_t j = 0; j < sqrLength - i; j++)
    {
      size_t upperIndex = i + (cols + 1) * j;
      if (matrix[upperIndex] == 0)
      {
        isUpperZero = true;
      }
      size_t lowerIndex = lineLength - 1 - i - (cols + 1) * j;
      if (matrix[lowerIndex] == 0)
      {
        isLowerZero = true;
      }

      if (isLowerZero && isUpperZero)
      {
        break;
      }
    }
    count += !isLowerZero + !isUpperZero;
    isUpperZero = false;
    isLowerZero = false;
  }
  return count;
}
