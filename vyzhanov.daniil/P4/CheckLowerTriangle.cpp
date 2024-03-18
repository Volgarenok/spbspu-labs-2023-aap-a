#include "CheckLowerTriangle.hpp"
#include <stdexcept>

bool vyzhanov::checkLowerTriangle(const int* matrix, size_t rows, size_t cols)
{
  size_t rowsCount = 0;
  size_t numZeroInRows = 0;
  size_t zerosShoudBe = cols;
  if (rows != cols)
  {
    throw std::logic_error("matrix must be square!");
  }
  if (rows * cols < 4)
  {
    return false;
  }
  for (size_t i = 0; i < rows * cols; i += cols)
  {
    zerosShoudBe -= 1;
    numZeroInRows = 0;
    for (size_t k = cols - numZeroInRows; k < cols; k++)
    {
      if (matrix[i + k] == 0)
      {
        numZeroInRows++;
      }
    }
    if (numZeroInRows == zerosShoudBe)
    {
      rowsCount++;
    }
  }
  if (rowsCount == rows)
  {
    return true;
  }
  else
  {
    return false;
  }
}
