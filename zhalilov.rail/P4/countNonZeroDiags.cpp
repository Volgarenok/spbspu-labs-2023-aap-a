#include "countNonZeroDiags.hpp"

#include <algorithm>

int zhalilov::countNonZeroDiags(int matrix[], int rows, int cols)
{
  int count = 0;
  int sqrLength = std::min(rows, cols);
  int lineLength = sqrLength * sqrLength;
  bool isUpperZero = false;
  bool isLowerZero = false;
  for (int i = 1; i < sqrLength; i++)
  {
    for (int j = 0; j < sqrLength - i; j++)
    {
      int upperIndex = i + (cols + 1) * j;
      if (matrix[upperIndex] == 0)
      {
        isUpperZero = true;
      } 
      int lowerIndex = lineLength - 1 - i - (cols + 1) * j;
      if (matrix[lowerIndex] == 0)
      {
        isLowerZero = true;
      }

      if (isLowerZero && isUpperZero)
      {
        break;
      }
    }
    count+= !isLowerZero + !isUpperZero;
    isUpperZero = false;
    isLowerZero = false;
  }
  return count;
}
