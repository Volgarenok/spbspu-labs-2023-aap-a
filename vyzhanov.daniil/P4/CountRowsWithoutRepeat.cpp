#include "CountRowsWithoutRepeat.hpp"

size_t vyzhanov::countRowsWithoutRepeat(const int* matrix, size_t rows, size_t cols)
{
  size_t countNum = 1;
  size_t countWithoutRep = 0;
  size_t check = 0;
  if (cols * rows == 1)
  {
    return 1;
  }
  for (size_t i = 0; i < rows * cols; i += cols)
  {
    countNum = 1;
    for (size_t j = 1; j <= cols - 1; j++)
    {
      check = 0;
      for (size_t k = cols - j; k > 0; k -= 1)
      {
        if (matrix[i + j - 1] == matrix[i + j + k - 1])
        {
          check++;
        }
      }
      if (check == 0)
      {
        countNum++;
      }
      if (countNum == cols)
      {
        countWithoutRep++;
      }
    }
  }
  return countWithoutRep;
}

